#include "pch.h"
#include "Hand.h"


namespace MTG {

	Hand::Hand () {
		this->m_MaxSize = 7;
	}


	Hand::~Hand () {
	}

	void Hand::addCard (CardInstance* card) {
		this->m_Cards.push_back(card);
	}

	void Hand::removeCard (CardInstance* card) {
		unsigned int idx = 0;
		for (; idx < this->m_Cards.size(); ++idx) {
			if (card == this->m_Cards[idx]) {
				break;
			}
		}

		this->m_Cards.erase(this->m_Cards.begin()+idx-1);
	}

	std::ostream& operator<< (std::ostream& stream, const Hand& hand) {
		for (CardInstance* const card : hand.m_Cards) {
			stream << *card;
		}

		return stream;
	}

	std::vector<const CardInstance*> Hand::getPlayableCards(const Mana mana) const {
		std::vector<const CardInstance*> result;

		for (CardInstance* card : this->m_Cards) {
			if (card->isAffordable(mana)) {
				result.push_back(card);
			}
		}

		return result;
	}

}


