#include <iostream>

#include "Game.h"
#include "Event/EGameStart.h"

namespace MTG {
	Game::Game (unsigned char playerCount, std::array<std::shared_ptr<Deck::DeckBase>, 6> decks) : Game(playerCount, decks, false) {}

  // TODO: Make a DeckInstance class
	Game::Game (unsigned char playerCount, std::array<std::shared_ptr<Deck::DeckBase>, 6> decks, bool verbose) {
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
	}


	Game::~Game () {
    std::cout << "Destroying Game object." << std::endl;
	}


  std::unique_ptr<EnvState> Game::getNextMoveOption () {
    switch (this->m_Phase) {
      case Game::PHASE_END:
        this->nextPlayer();
      case Game::PHASE_BEGINNING:
      case Game::PHASE_UNTAP:
        this->m_Players[this->m_CurrentPlayer]->untapAll();
      case Game::PHASE_DRAW:
        this->m_Players[this->m_CurrentPlayer]->drawCards(1);
      case Game::PHASE_MAIN:
        break;
    }


    std::unique_ptr<Matrix<unsigned char, Card::Instance::VECTOR_SIZE>> environment = this->vectorize();
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


  void Game::reset () {
    std::cout << "Resetting..." << std::endl;
    for (unsigned char i = 0; i < this->m_PlayerCount; ++i) {
      std::unique_ptr<Deck::Instance> deck = this->m_Decks[i]->newInstance();
			this->m_Players[i] = std::make_shared<PlayerState>(20, move(deck), i);

      this->m_EventManager.reg("GameStart", this->m_Players[i]);
      this->m_EventManager.reg("NewStep", this->m_Players[i]);
		}

    this->m_EventManager.trigger(std::make_unique<Event::EGameStart>());

    std::cout << "Initializing state variables..." << std::endl;
		this->m_CurrentPlayer = 0;
		this->m_Phase = Game::PHASE_BEGINNING;
	}


	void Game::nextPlayer () {
		this->m_CurrentPlayer = (this->m_CurrentPlayer + 1) % this->m_PlayerCount;
	}

  std::unique_ptr<Matrix<unsigned char, Card::Instance::VECTOR_SIZE>> Game::vectorize () const {
    std::cout << "Vectorizing Game..." << std::endl;
    std::size_t playerIdx = 0;
    std::unique_ptr<Matrix<unsigned char, Card::Instance::VECTOR_SIZE>> result = this->m_Players[this->m_CurrentPlayer]->vectorize(false, playerIdx);

    std::size_t player = this->m_CurrentPlayer;
    player = (player + 1) % this->m_PlayerCount;
    ++playerIdx;
    while (player != this->m_CurrentPlayer) {
      std::unique_ptr<Matrix<unsigned char, Card::Instance::VECTOR_SIZE>> playerVec = this->m_Players[player]->vectorize(true, playerIdx);
      result->append(playerVec);
      player = (player + 1) % this->m_PlayerCount;
      ++playerIdx;
    }

    return result;
  }

}
