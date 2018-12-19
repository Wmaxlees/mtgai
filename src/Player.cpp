#include "pch.h"
#include "Player.h"
#include "Game.h"

#include <iostream>

namespace MTG {

	Player::Player (unsigned char startingHealth, Library* library) {
		this->m_Health = startingHealth;
		this->m_Library = library;
	}


	Player::~Player () {
    std::cout << "Destroying player object." << std::endl;
		if (this->m_Library) {
			delete this->m_Library;
		}
		this->m_Library = nullptr;
	}


	bool Player::drawCards (unsigned char amount) {
		for (unsigned char i = 0; i < amount; ++i) {
			if (this->m_Library->empty()) {
				return false;
			}

			this->m_Hand.addCard(this->m_Library->getNextCard());
		}

		return true;
	}

  void Player::untapAll () {
    this->m_Board.untapAll();
  }

	void Player::printHand () const {
		std::cout << this->m_Hand;
	}

	void Player::clearMana () {
		this->m_Mana.clear();
	}

	void Player::playCard (const CardInstance* card) {
		this->m_Mana.remove(card->getCost());
		this->m_Hand.removeCard(const_cast<CardInstance*>(card));
		this->m_Board.addCard(const_cast<CardInstance*>(card));
	}


	std::vector<const CardInstance*> Player::getInstantSpeedMoves () const {
		std::vector<const CardInstance*> moves;

		return moves;
	}


	std::vector<const CardInstance*> Player::getMainPhaseMoves () const {
		return this->m_Hand.getPlayableCards(this->m_Mana);
	}


	std::vector<const CardInstance*> Player::getPossibleAttackers () const {
		return this->m_Board.getCardsOfType(Card::CREATURE, true);
	}


	std::vector<const CardInstance*> Player::getPossibleBlockers () const {
		return this->m_Board.getCardsOfType(Card::CREATURE, true);
	}


  Matrix<unsigned char>* Player::vectorize () const {
    std::cout << "Vectorizing Player..." << std::endl;

    Matrix<unsigned char>* result = this->m_Board.vectorize();
    Matrix<unsigned char>* hand = this->m_Hand.vectorize();
    std::cout << "Combining board and hand." << std::endl;
    result->append(const_cast<const Matrix<unsigned char>* const>(hand));
    std::cout << "Finished combining board and hand." << std::endl;
    delete hand;
    std::cout << "TEST" << std::endl;

    return result;
  }

}
