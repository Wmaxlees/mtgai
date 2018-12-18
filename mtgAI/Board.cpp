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

}
