#include <algorithm>
#include <iostream>

#include "Hand.h"


namespace MTG {

	Hand::Hand () {
		this->m_MaxSize = 7;
	}


	Hand::~Hand () {
	}

	void Hand::addCard (std::shared_ptr<Card::Instance> card) {
		this->m_Cards.push_back(move(card));
	}

  std::shared_ptr<Card::Instance> Hand::removeCard (std::shared_ptr<const Card::Instance> card) {
		auto it = std::find(this->m_Cards.begin(), this->m_Cards.end(), card);

    if (it == this->m_Cards.end()) {
      throw -1;
    }

    std::shared_ptr<Card::Instance> result = *it;
    this->m_Cards.erase(it);

    return result;
	}

	std::ostream& operator<< (std::ostream& stream, const Hand& hand) {
		for (const std::shared_ptr<Card::Instance>& card : hand.m_Cards) {
			stream << *card;
		}

		return stream;
	}

	std::vector<std::shared_ptr<const Card::Instance>> Hand::getPlayableCards (const Mana mana) const {
		std::vector<std::shared_ptr<const Card::Instance>> result;

		for (const std::shared_ptr<Card::Instance> card : this->m_Cards) {
			if (card->isAffordable(mana)) {
				result.push_back(card);
			}
		}

		return result;
	}

  std::unique_ptr<Matrix<unsigned char, Card::Instance::VECTOR_SIZE>> Hand::vectorize (std::size_t playerIdx) const {
    std::unique_ptr<Matrix<unsigned char, Card::Instance::VECTOR_SIZE>> result = std::make_unique<Matrix<unsigned char, Card::Instance::VECTOR_SIZE>>();

    for (const std::shared_ptr<Card::Instance>& card : this->m_Cards) {
      std::array<unsigned char, Card::Instance::VECTOR_SIZE> cardVector = card->vectorize(false, playerIdx);
      result->put(cardVector);
    }

    return result;
  }

}
