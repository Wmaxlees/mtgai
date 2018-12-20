
#include "Player.h"
#include "Game.h"

#include <iostream>

namespace MTG {

	Player::Player (unsigned char startingHealth, std::unique_ptr<Deck::Instance> deck) {
		this->m_Health = startingHealth;
		this->m_Deck = move(deck);
	}


	Player::~Player () {
    std::cout << "Destroying player object." << std::endl;
	}


  void Player::shuffle () {
    this->m_Deck->shuffle();
  }


	bool Player::drawCards (unsigned char amount) {
		for (unsigned char i = 0; i < amount; ++i) {
			if (this->m_Deck->empty()) {
				return false;
			}

			this->m_Hand.addCard(this->m_Deck->getNextCard());
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

	void Player::playCard (std::shared_ptr<const Card::Instance> card) {
		this->m_Mana.remove(card->getCost());
		std::shared_ptr<Card::Instance> playedCard = this->m_Hand.removeCard(card);
		this->m_Board.addCard(playedCard);
	}


	std::vector<std::shared_ptr<const Card::Instance>> Player::getInstantSpeedMoves () const {
		std::vector<std::shared_ptr<const Card::Instance>> moves;

		return moves;
	}


	std::vector<std::shared_ptr<const Card::Instance>> Player::getMainPhaseMoves () const {
		return this->m_Hand.getPlayableCards(this->m_Mana);
	}


	std::vector<std::shared_ptr<const Card::Instance>> Player::getPossibleAttackers () const {
		return this->m_Board.getCardsOfType(Card::CardBase::CREATURE, true);
	}


	std::vector<std::shared_ptr<const Card::Instance>> Player::getPossibleBlockers () const {
		return this->m_Board.getCardsOfType(Card::CardBase::CREATURE, true);
	}


  std::unique_ptr<Matrix<unsigned char, 12>> Player::vectorize () const {
    std::cout << "Vectorizing Player..." << std::endl;

    std::unique_ptr<Matrix<unsigned char, 12>> result = this->m_Board.vectorize();
    std::unique_ptr<Matrix<unsigned char, 12>> hand = this->m_Hand.vectorize();
    result->append(hand);

    return move(result);
  }

}
