
#include "Game.h"

#include <iostream>

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


  void Game::step () {
    switch (this->m_Phase) {
      case Game::PHASE_END:
        this->nextPlayer();
      case Game::PHASE_BEGINNING:
      case Game::PHASE_UNTAP:
        this->m_Players[this->m_CurrentPlayer]->untapAll();
      case Game::PHASE_DRAW:
        this->m_Players[this->m_CurrentPlayer]->drawCards(1);
      case Game::PHASE_MAIN:
        return;
        break;


    }
  }


  std::unique_ptr<Matrix<unsigned char, 12>> Game::reset () {
    std::cout << "Resetting..." << std::endl;
    for (unsigned char i = 0; i < this->m_PlayerCount; ++i) {
      std::unique_ptr<Deck::Instance> deck = this->m_Decks[i]->newInstance();
			this->m_Players[i] = std::make_unique<Player>(20, move(deck));
		}

    std::cout << "Drawing opening hands..." << std::endl;
		this->drawOpeningCards();

    std::cout << "Initializing state variables..." << std::endl;
		this->m_CurrentPlayer = 0;
		this->m_Phase = Game::PHASE_BEGINNING;

    std::unique_ptr<Matrix<unsigned char, 12>> result = this->vectorize();

    return result;
	}



  void Game::drawOpeningCards () {
		for (unsigned char i = 0; i < this->m_PlayerCount; ++i) {
      this->m_Players[i]->shuffle();
			this->m_Players[i]->drawCards(7);
			if (this->m_Verbose) {
				std::cout << "Player " << i + 1 << " Starting Hand:" << std::endl;
				this->m_Players[i]->printHand();
				std::cout << std::endl << std::endl;
			}
		}
	}


	void Game::nextPlayer () {
		this->m_CurrentPlayer = (this->m_CurrentPlayer + 1) % this->m_PlayerCount;
	}

  std::unique_ptr<Matrix<unsigned char, 12>> Game::vectorize () const {
    std::cout << "Vectorizing Game..." << std::endl;
    std::unique_ptr<Matrix<unsigned char, 12>> result = this->m_Players[this->m_CurrentPlayer]->vectorize();

    std::size_t player = this->m_CurrentPlayer;
    player = (player + 1) % this->m_PlayerCount;
    while (player != this->m_CurrentPlayer) {
      std::unique_ptr<Matrix<unsigned char, 12>> playerVec = this->m_Players[player]->vectorize();
      result->append(playerVec);
      player = (player + 1) % this->m_PlayerCount;
    }
    
    return result;
  }

}
