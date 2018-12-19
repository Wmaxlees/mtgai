#include <iostream>

#include "pch.h"
#include "Board.h"

namespace MTG {

	Board::Board () {
	}


	Board::~Board () {
		for (CardInstance* card : this->m_Cards) {
			delete card;
			card = nullptr;
		}
	}


	void Board::addCard (CardInstance* card) {
		this->m_Cards.push_back(card);
	}

  void Board::untapAll () {
    for (CardInstance* card : this->m_Cards) {
      if (card->isTapped()) {
        card->untap();
      }
    }
  }


	std::vector<const CardInstance*> Board::getCardsOfType(unsigned int type, bool onlyUntapped) const {
		std::vector<const CardInstance*> result;

		for (CardInstance* card : this->m_Cards) {
			if (card->isType(type)) {
				if (onlyUntapped && card->isTapped()) {
					continue;
				}

				result.push_back(card);
			}
		}

		return result;
	}


	std::vector<const CardInstance*> Board::getCardsOfType(unsigned int type) const {
		return this->getCardsOfType(type, false);
	}


  Matrix<unsigned char>* Board::vectorize () const {
    std::cout << "Vectorizing Board..." << std::endl;
    Matrix<unsigned char>* result = new Matrix<unsigned char>();

    for (CardInstance* card : this->m_Cards) {
      unsigned char* cardVector = card->vectorize(true);
      result->put(cardVector, 12);
      delete [] cardVector;
    }

    return result;
  }

}
