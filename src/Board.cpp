#include <iostream>

#include "Board.h"

namespace MTG {

	Board::Board () {
	}


	Board::~Board () {
	}


	void Board::addCard (std::shared_ptr<Card::Instance> card) {
		this->m_Cards.push_back(card);
	}

  void Board::untapAll () {
    for (std::shared_ptr<Card::Instance> card : this->m_Cards) {
      if (card->isTapped()) {
        card->untap();
      }
    }
  }


	std::vector<std::shared_ptr<const Card::Instance>> Board::getCardsOfType(unsigned int type, bool onlyUntapped) const {
		std::vector<std::shared_ptr<const Card::Instance>> result;

		for (std::shared_ptr<const Card::Instance> card : this->m_Cards) {
			if (card->isType(type)) {
				if (onlyUntapped && card->isTapped()) {
					continue;
				}

				result.push_back(card);
			}
		}

		return result;
	}


	std::vector<std::shared_ptr<const Card::Instance>> Board::getCardsOfType(unsigned int type) const {
		return this->getCardsOfType(type, false);
	}


  std::unique_ptr<Matrix<unsigned char, Card::Instance::VECTOR_SIZE>> Board::vectorize (std::size_t playerIdx) const {
    std::unique_ptr<Matrix<unsigned char, Card::Instance::VECTOR_SIZE>> result = std::make_unique<Matrix<unsigned char, Card::Instance::VECTOR_SIZE>>();

    for (std::shared_ptr<const Card::Instance> card : this->m_Cards) {
      std::array<unsigned char, Card::Instance::VECTOR_SIZE> cardVector = card->vectorize(true, playerIdx);
      result->put(cardVector);
    }

    return result;
  }



}
