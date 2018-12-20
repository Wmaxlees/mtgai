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
		unsigned int idx = 0;
		for (; idx < this->m_Cards.size(); ++idx) {
			if (&(*card) == &(*(this->m_Cards[idx]))) {
				break;
			}
		}

    std::shared_ptr<Card::Instance> result = this->m_Cards.at(idx);
		this->m_Cards.erase(this->m_Cards.begin()+idx-1);
    return result;
	}

	std::ostream& operator<< (std::ostream& stream, const Hand& hand) {
		for (const std::shared_ptr<Card::Instance>& card : hand.m_Cards) {
			stream << *card;
		}

		return stream;
	}

	std::vector<std::shared_ptr<const Card::Instance>> Hand::getPlayableCards(const Mana mana) const {
		std::vector<std::shared_ptr<const Card::Instance>> result;

		for (const std::shared_ptr<Card::Instance> card : this->m_Cards) {
			if (card->isAffordable(mana)) {
				result.push_back(card);
			}
		}

		return result;
	}

  std::unique_ptr<Matrix<unsigned char, 12>> Hand::vectorize () const {
    std::unique_ptr<Matrix<unsigned char, 12>> result = std::make_unique<Matrix<unsigned char, 12>>();

    for (const std::shared_ptr<Card::Instance>& card : this->m_Cards) {
      std::array<unsigned char, 12> cardVector = card->vectorize(false);
      result->put(cardVector);
    }

    return result;
  }

}
