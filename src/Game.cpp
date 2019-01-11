#include <iostream>

#include "Game.h"
#include "Event/GameStartEvent.h"
#include "Event/NewPhaseEvent.h"
#include "Event/PassEvent.h"
#include "Event/PlayCardEvent.h"
#include "Event/StartDrawStepEvent.h"
#include "Event/TapLandEvent.h"

namespace mtg {
	Game::Game(unsigned char playerCount, std::array<std::shared_ptr<deck::DeckBase>, 6> decks) : Game(playerCount, decks, false) {}

	// TODO: Make a DeckInstance class
	Game::Game(unsigned char playerCount, std::array<std::shared_ptr<deck::DeckBase>, 6> decks, bool verbose) {
		this->m_PlayerCount = playerCount;
		this->m_CurrentPlayer = 0;
		this->m_PriorityPlayer = 0;

		this->m_Verbose = verbose;

		for (unsigned int i = 0; i < 6; ++i) {
			this->m_Decks[i] = decks[i];
		}

		for (unsigned char i = 0; i < 6; ++i) {
			this->m_Players[i] = nullptr;
		}

		this->m_EventManager.reg("Pass", this);
	}


	Game::~Game() {
		std::cout << "Destroying Game object." << std::endl;
	}

	const std::vector<std::shared_ptr<action::ActionBase>> Game::getCurrentMoveList() {
		std::vector<std::shared_ptr<action::ActionBase>> result;
		switch (this->m_Phase) {
		case Game::PHASE_END:
		case Game::PHASE_BEGINNING:
		case Game::PHASE_UNTAP:
			break;
		case Game::PHASE_DRAW:
			this->m_EventManager.trigger(std::make_unique<event::StartDrawStepEvent>(this->m_CurrentPlayer));
			break;
		case Game::PHASE_MAIN:
			result = this->m_Players[this->m_CurrentPlayer]->getMainPhaseMoves();
			break;
		case Game::PHASE_ATTACKERS:
			for (auto targetIdx : this->getAttackablePlayerIdxs()) {
				std::vector<std::shared_ptr<action::ActionBase>> possibleAttacks = this->m_Players[this->m_CurrentPlayer]->getDeclareAttackerMoves(targetIdx);
				for (auto it = possibleAttacks.begin(); it != possibleAttacks.end(); ++it) {
					result.push_back(*it);
				}
			}
			break;
		}
		return result;
	}

	std::unique_ptr<EnvState> Game::getCurrentState() {
		std::unique_ptr<Matrix<unsigned char, card::CardInstance::VECTOR_SIZE>> environment = this->vectorize();
		bool gameOver = false;
		for (std::size_t idx = 0; idx < this->m_PlayerCount; ++idx) {
			gameOver &= this->m_Players[idx]->isDead();
		}
		int reward = 0;

		std::unique_ptr<EnvState> result = std::make_unique<EnvState>(
			move(environment),
			reward,
			gameOver,
			nullptr
			);

		return move(result);
	}

	void Game::reset() {
		std::cout << "Resetting..." << std::endl;

		for (unsigned char i = 0; i < this->m_PlayerCount; ++i) {
			std::unique_ptr<deck::DeckInstance> deck = this->m_Decks[i]->newInstance();
			this->m_Players[i] = std::make_shared<PlayerState>(20, move(deck), i);

			this->m_EventManager.reg("GameStart", &(*this->m_Players[i]));
			this->m_EventManager.reg("NewPhase", &(*this->m_Players[i]));
			this->m_EventManager.reg("TapLand", &(*this->m_Players[i]));
			this->m_EventManager.reg("PlayCard", &(*this->m_Players[i]));
			this->m_EventManager.reg("StartDrawStep", &(*this->m_Players[i]));
		}

		this->m_EventManager.trigger(std::make_unique<event::GameStartEvent>());

		std::cout << "Initializing state variables..." << std::endl;
		this->m_CurrentPlayer = 0;
		this->m_Phase = Game::PHASE_BEGINNING;
	}

	void Game::handle(std::unique_ptr<event::EventBase>& event) {
		if (event->getType() == "Pass") {
			this->advancePhase();
			return;
		}
	}


	void Game::advancePhase() {
		switch (this->m_Phase) {
		
		case Game::PHASE_BEGINNING:
			this->m_Phase = Game::PHASE_UNTAP;
			break;
		case Game::PHASE_UNTAP:
			this->m_Phase = Game::PHASE_DRAW;
			break;
		case Game::PHASE_DRAW:
			this->m_Phase = Game::PHASE_MAIN;
			break;
		case Game::PHASE_MAIN:
			this->m_Phase = Game::PHASE_COMBAT;
			break;
		case Game::PHASE_COMBAT:
			this->m_Phase = Game::PHASE_ATTACKERS;
			break;
		case Game::PHASE_ATTACKERS:
			this->m_Phase = Game::PHASE_BLOCKERS;
			break;
		case Game::PHASE_BLOCKERS:
			this->m_Phase = Game::PHASE_DAMAGE;
			break;
		case Game::PHASE_DAMAGE:
			this->m_Phase = Game::PHASE_MAIN_SECOND;
			break;
		case Game::PHASE_MAIN_SECOND:
			this->m_Phase = Game::PHASE_END;
			break;
		case Game::PHASE_END:
			this->m_Phase = Game::PHASE_PASS_TURN;
			break;
		case Game::PHASE_PASS_TURN:
			this->m_Phase = Game::PHASE_BEGINNING;
			this->nextPlayer();
			std::cout << *this << std::endl;
			std::cout << "Press Enter to Continue" << std::endl;
			std::cin.ignore();
			break;
		}

		this->m_EventManager.trigger(std::make_unique<event::NewPhaseEvent>(this->m_CurrentPlayer, this->m_Phase));
	}


	void Game::nextPlayer() {
		this->m_CurrentPlayer = (this->m_CurrentPlayer + 1) % this->m_PlayerCount;
	}

	std::unique_ptr<Matrix<unsigned char, card::CardInstance::VECTOR_SIZE>> Game::vectorize() const {
		unsigned char playerIdx = 0;
		std::unique_ptr<Matrix<unsigned char, card::CardInstance::VECTOR_SIZE>> result = this->m_Players[this->m_CurrentPlayer]->vectorize(false, playerIdx);

		unsigned char player = this->m_CurrentPlayer;
		player = (player + 1) % this->m_PlayerCount;
		++playerIdx;
		while (player != this->m_CurrentPlayer) {
			std::unique_ptr<Matrix<unsigned char, card::CardInstance::VECTOR_SIZE>> playerVec = this->m_Players[player]->vectorize(true, playerIdx);
			result->append(playerVec);
			player = (player + 1) % this->m_PlayerCount;
			++playerIdx;
		}

		return result;
	}

	void Game::perform(std::shared_ptr<const action::ActionBase> action) {
		if (action->getType() == "TapLandAction") {
			std::cout << "Player " << (unsigned int)this->m_CurrentPlayer << " tapping " << action->getCard()->getName() << std::endl;
			this->m_EventManager.trigger(std::make_unique<event::TapLandEvent>(action->getPlayerIdx(), action->getCard()));
		}

		if (action->getType() == "PlayCardAction") {
			std::cout << "Player " << (unsigned int)this->m_CurrentPlayer << " playing " << action->getCard()->getName() << std::endl;
			this->m_EventManager.trigger(std::make_unique<event::PlayCardEvent>(action->getPlayerIdx(), action->getCard()));
		}

		
	}

	void Game::pass() {
		// std::cout << "Player " << (unsigned int)this->m_CurrentPlayer << " passing" << std::endl;
		this->m_EventManager.trigger(std::make_unique<event::PassEvent>());
	}

	std::vector<unsigned char> Game::getAttackablePlayerIdxs() {
		std::vector<unsigned char> result;

		unsigned char possibleTarget = (this->m_CurrentPlayer + 1) % this->m_PlayerCount;
		while (possibleTarget != this->m_CurrentPlayer) {
			result.push_back(possibleTarget);
			possibleTarget = (possibleTarget + 1) % this->m_PlayerCount;
		}

		return result;
	}


	std::ostream& operator<< (std::ostream& stream, const Game& game) {
		for (unsigned char playerIdx = 0; playerIdx < game.m_PlayerCount; ++playerIdx) {
			stream << *game.m_Players[playerIdx] << "\n" << std::endl;
		}

		return stream;
	}

}
