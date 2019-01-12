#include "Event/DeclareAttackerEvent.h"
#include "Event/NewPhaseEvent.h"
#include "Event/PlayCardEvent.h"
#include "Event/StartDrawStepEvent.h"
#include "Event/TapLandEvent.h"
#include "PlayerState.h"
#include "Game.h"

#include <iostream>

namespace mtg {

	PlayerState::PlayerState(unsigned char startingHealth, std::unique_ptr<deck::DeckInstance> deck, unsigned char uniqueID) {
		this->m_UniqueID = uniqueID;
		this->m_Health = startingHealth;
		this->m_Deck = move(deck);
	}


	PlayerState::~PlayerState() {
		std::cout << "Destroying player object." << std::endl;
	}

	void PlayerState::playCard(std::shared_ptr<const card::CardInstance> card) {
		this->m_Mana.remove(card->getCost());
		std::shared_ptr<card::CardInstance> playedCard = this->m_Hand.removeCard(card);
		if (playedCard->isType(card::CardBase::CREATURE)) {
			playedCard->setSummoningSickness();
		}
		this->m_Board.addCard(playedCard);
	}


	bool PlayerState::isDead() {
		return this->m_Health <= 0;
	}

	const std::vector<std::shared_ptr<action::ActionBase>> PlayerState::getInstantSpeedMoves() const {
		std::vector<std::shared_ptr<action::ActionBase>> moves;

		return moves;
	}


	const std::vector<std::shared_ptr<action::ActionBase>> PlayerState::getMainPhaseMoves() const {
		std::vector<std::shared_ptr<action::ActionBase>> result = this->m_Board.getTappableLands(this->m_UniqueID);

		std::vector<std::shared_ptr<action::ActionBase>> playableAbilities = this->m_Board.getPlayableAbilities(this->m_UniqueID, this->m_Mana);
		for (auto it = playableAbilities.begin(); it != playableAbilities.end(); ++it) {
			result.push_back(move(*it));
		}
		
		std::vector<std::shared_ptr<action::ActionBase>> playableCards = this->m_Hand.getPlayableCards(this->m_UniqueID, this->m_Mana);
		for (auto it = playableCards.begin(); it != playableCards.end(); ++it) {
			result.push_back(move(*it));
		}

		return result;
	}


	const std::vector<std::shared_ptr<action::ActionBase>> PlayerState::getDeclareAttackerMoves(unsigned char targetIdx) const {
		std::vector<std::shared_ptr<action::ActionBase>> result = this->m_Board.getDeclareAttackerMoves(this->m_UniqueID, targetIdx);
		return result;
	}


	const std::vector<std::shared_ptr<action::ActionBase>> PlayerState::getPossibleBlockers() const {
		std::vector<std::shared_ptr<action::ActionBase>> moves;

		return moves;
	}


	void PlayerState::handle(std::unique_ptr<event::EventBase>& event) {
		if (event->getType() == "GameStart") {
			this->handleGameStart();
			return;
		}

		if (event->getType() == "NewPhase") {
			event::NewPhaseEvent* castEvent = (event::NewPhaseEvent*)&(*event);
			this->handleNewPhase(*castEvent);
			return;
		}

		if (event->getType() == "PlayCard") {
			event::PlayCardEvent* castEvent = (event::PlayCardEvent*)&(*event);
			if (castEvent->getPlayerIdx() != this->m_UniqueID) {
				return;
			}

			this->playCard(castEvent->getCard());
		}

		if (event->getType() == "StartDrawStep") {
			event::StartDrawStepEvent* castEvent = (event::StartDrawStepEvent*)&(*event);
			if (castEvent->getPlayerIdx() != this->m_UniqueID) {
				return;
			}

			this->drawCards(1);
		}

		if (event->getType() == "TapLand") {
			event::TapLandEvent* castEvent = (event::TapLandEvent*)&(*event);
			this->m_Mana.add(castEvent->getCard()->getMana());
			castEvent->getCard()->tap();
		}


		if (event->getType() == "DeclareAttacker") {
			event::DeclareAttackerEvent* castEvent = (event::DeclareAttackerEvent*)&(*event);
			// Make an actual object for keeping track of attack moves that are already declared
			// this->m_CurrentAttackers.push_back(std::make_shared<action::)
		}
	}


	std::unique_ptr<Matrix<unsigned char, card::CardInstance::VECTOR_SIZE>> PlayerState::vectorize(bool hideHand, unsigned char playerIdx) const {
		std::unique_ptr<Matrix<unsigned char, card::CardInstance::VECTOR_SIZE>> result = this->m_Board.vectorize(playerIdx);

		if (!hideHand) {
			std::unique_ptr<Matrix<unsigned char, card::CardInstance::VECTOR_SIZE>> hand = this->m_Hand.vectorize(playerIdx);
			result->append(hand);
		}

		return move(result);
	}


	void PlayerState::handleGameStart() {
		std::cout << "Game starting for player: " << (unsigned int)this->m_UniqueID << std::endl;
		this->m_Deck->shuffle();
		this->drawCards(7);
		std::cout << "Opening Hand: " << std::endl;
		std::cout << this->m_Hand << std::endl;
	}

	void PlayerState::handleNewPhase(event::NewPhaseEvent& newPhase) {
		this->m_Mana.clear();
		if (newPhase.getPlayerID() != this->m_UniqueID) {
			return;
		}

		if (newPhase.getPhaseID() == Game::PHASE_BEGINNING) {
			this->m_Board.removeAllSummoningSickness();
		}

		if (newPhase.getPhaseID() == Game::PHASE_UNTAP) {
			this->m_Board.untapAll();
			return;
		}

		if (newPhase.getPhaseID() == Game::PHASE_DRAW) {
			this->drawCards(1);
			return;
		}
	}

	bool PlayerState::drawCards(unsigned char amount) {
		for (unsigned char i = 0; i < amount; ++i) {
			if (this->m_Deck->empty()) {
				return false;
			}

			this->m_Hand.addCard(this->m_Deck->getNextCard());
		}

		return true;
	}


	const std::vector<std::shared_ptr<action::ActionBase>> PlayerState::getAttackers() const {
		return this->m_CurrentAttackers;
	}


	std::ostream& operator<< (std::ostream& stream, const PlayerState& player) {
		stream << (unsigned int)player.m_Health << "/20 " << player.m_Mana << std::endl;
		stream << "Hand: " << player.m_Hand << std::endl;
		stream << "Board: " << player.m_Board << std::endl;
		return stream;
	}

}
