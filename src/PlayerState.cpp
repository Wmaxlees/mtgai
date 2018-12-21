#include "Event/ENewStep.h"
#include "PlayerState.h"
#include "Game.h"

#include <iostream>

namespace MTG {

	PlayerState::PlayerState (unsigned char startingHealth, std::unique_ptr<Deck::Instance> deck, unsigned char uniqueID) {
    this->m_UniqueID = uniqueID;
		this->m_Health = startingHealth;
		this->m_Deck = move(deck);
	}


	PlayerState::~PlayerState () {
    std::cout << "Destroying player object." << std::endl;
	}


  void PlayerState::shuffle () {
    this->m_Deck->shuffle();
  }


	bool PlayerState::drawCards (unsigned char amount) {
		for (unsigned char i = 0; i < amount; ++i) {
			if (this->m_Deck->empty()) {
				return false;
			}

			this->m_Hand.addCard(this->m_Deck->getNextCard());
		}

		return true;
	}

  void PlayerState::untapAll () {
    this->m_Board.untapAll();
  }

	void PlayerState::clearMana () {
		this->m_Mana.clear();
	}

	void PlayerState::playCard (std::shared_ptr<const Card::Instance> card) {
		this->m_Mana.remove(card->getCost());
		std::shared_ptr<Card::Instance> playedCard = this->m_Hand.removeCard(card);
		this->m_Board.addCard(playedCard);
	}


  bool PlayerState::isDead () {
    return this->m_Health <= 0;
  }

	std::vector<std::shared_ptr<const Card::Instance>> PlayerState::getInstantSpeedMoves () const {
		std::vector<std::shared_ptr<const Card::Instance>> moves;

		return moves;
	}


	std::vector<std::shared_ptr<const Card::Instance>> PlayerState::getMainPhaseMoves () const {
		return this->m_Hand.getPlayableCards(this->m_Mana);
	}


	std::vector<std::shared_ptr<const Card::Instance>> PlayerState::getPossibleAttackers () const {
		return this->m_Board.getCardsOfType(Card::CardBase::CREATURE, true);
	}


	std::vector<std::shared_ptr<const Card::Instance>> PlayerState::getPossibleBlockers () const {
		return this->m_Board.getCardsOfType(Card::CardBase::CREATURE, true);
	}


  void PlayerState::handle (std::unique_ptr<Event::EventBase>& event) {
    if (event->getType() == "GameStart") {
      this->handleGameStart();
      return;
    }

    if (event->getType() == "NewStep") {
      Event::ENewStep* castEvent = (Event::ENewStep*)&(*event);
      this->handleNewStep(*castEvent);
      return;
    }
  }


  std::unique_ptr<Matrix<unsigned char, Card::Instance::VECTOR_SIZE>> PlayerState::vectorize (bool hideHand, std::size_t playerIdx) const {
    std::cout << "Vectorizing PlayerState..." << std::endl;

    std::unique_ptr<Matrix<unsigned char, Card::Instance::VECTOR_SIZE>> result = this->m_Board.vectorize(playerIdx);

    if (!hideHand) {
      std::unique_ptr<Matrix<unsigned char, Card::Instance::VECTOR_SIZE>> hand = this->m_Hand.vectorize(playerIdx);
      result->append(hand);
    }

    return move(result);
  }


  void PlayerState::handleGameStart () {
    std::cout << "Game starting for player: " << (unsigned int)this->m_UniqueID << std::endl;
    this->shuffle();
    this->drawCards(7);
    std::cout << "Opening Hand: " << std::endl;
    std::cout << this->m_Hand << std::endl;
  }

  void PlayerState::handleNewStep (Event::ENewStep& newStep) {
    if (newStep.getPlayerID() != this->m_UniqueID) {
      return;
    }
  }

}
