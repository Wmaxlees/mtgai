#include <iostream>

#include "pch.h"
#include "Hand.h"


namespace MTG {

	Hand::Hand () {
		this->m_MaxSize = 7;
	}


	Hand::~Hand () {
	}

	void Hand::addCard (std::shared_ptr<CardInstance> card) {
		this->m_Cards.push_back(move(card));
	}

	void Hand::removeCard (std::shared_ptr<CardInstance> card) {
		unsigned int idx = 0;
		for (; idx < this->m_Cards.size(); ++idx) {
			if (card == this->m_Cards[idx]) {
				break;
			}
		}

		this->m_Cards.erase(this->m_Cards.begin()+idx-1);
	}

	std::ostream& operator<< (std::ostream& stream, const Hand& hand) {
		for (const std::shared_ptr<CardInstance>& card : hand.m_Cards) {
			stream << *card;
		}

		return stream;
	}

	std::vector<std::shared_ptr<CardInstance>> Hand::getPlayableCards(const Mana mana) const {
		std::vector<std::shared_ptr<CardInstance>> result;

		for (const std::shared_ptr<CardInstance> card : this->m_Cards) {
			if (card->isAffordable(mana)) {
				result.push_back(card);
			}
		}

		return result;
	}

  std::unique_ptr<Matrix<unsigned char>> Hand::vectorize () const {
    std::cout << "Vectorizing Hand..." << std::endl;
    std::unique_ptr<Matrix<unsigned char>> result = std::make_unique<Matrix<unsigned char>>();

    for (const std::shared_ptr<CardInstance>& card : this->m_Cards) {
      std::unique_ptr<unsigned char[]> cardVector = card->vectorize(false);
      result->put(move(cardVector), 12);
    }

    return result;
  }

}
