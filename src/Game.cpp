#include "pch.h"
#include "Game.h"

#include <iostream>

#include "vectorize.h"

namespace MTG {
	Game::Game (unsigned char playerCount, Library* decks[]) : Game(playerCount, decks, false) {}

  // TODO: Make a DeckInstance class
	Game::Game (unsigned char playerCount, Library* decks[], bool verbose) {
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
		for (unsigned char i = 0; i < 6; ++i) {
			delete this->m_Players[i];
			this->m_Players[i] = nullptr;

      // TODO: Make DeckInstance!!!
      // delete this->m_Decks[i];
			// this->m_Decks[i] = nullptr;
		}

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


  Matrix<unsigned char>* Game::reset () {
    std::cout << "Resetting..." << std::endl;
    for (unsigned char i = 0; i < 6; ++i) {
      if (this->m_Players[i]) {
        delete this->m_Players[i];
      }
			this->m_Players[i] = nullptr;
		}

    for (unsigned char i = 0; i < this->m_PlayerCount; ++i) {
			this->m_Players[i] = new Player(20, this->m_Decks[i]);
		}

    std::cout << "Drawing opening hands..." << std::endl;
		this->drawOpeningCards();

    std::cout << "Initializing state variables..." << std::endl;
		this->m_CurrentPlayer = 0;
		this->m_Phase = Game::PHASE_BEGINNING;

    return this->vectorize();
	}



  void Game::drawOpeningCards () {
		for (unsigned char i = 0; i < this->m_PlayerCount; ++i) {
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

  Matrix<unsigned char>* Game::vectorize () const {
    std::cout << "Vectorizing Game..." << std::endl;
    Matrix<unsigned char>* result = this->m_Players[this->m_CurrentPlayer]->vectorize();

    std::cout << "Finished vectorizing current player." << std::endl;

    return result;
  }

}
