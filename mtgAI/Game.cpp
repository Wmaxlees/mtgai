#include "pch.h"
#include "Game.h"

#include <iostream>

namespace MTG {
	Game::Game (unsigned char playerCount, std::vector<Library*> decks) : Game(playerCount, decks, false) {
	}


	Game::Game (unsigned char playerCount, std::vector<Library*> decks, bool verbose) {
		for (unsigned char i = 0; i < playerCount; ++i) {
			this->m_Players[i] = new Player(20, decks[i]);
		}

		for (unsigned char i = playerCount; i < 6; ++i) {
			this->m_Players[i] = nullptr;
		}

		this->m_PlayerCount = playerCount;
		this->m_CurrentPlayer = 0;
		this->m_PriorityPlayer = 0;

		this->m_Verbose = verbose;
	}


	Game::~Game () {
		for (unsigned char i = 0; i < 6; ++i) {
			delete this->m_Players[i];
			this->m_Players[i] = nullptr;
		}
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


	void Game::initialize () {
		this->drawOpeningCards();
		this->m_CurrentPlayer = 0;
		this->m_Phase = Game::PHASE_BEGINNING;
	}

}
