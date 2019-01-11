#include <algorithm>
#include <iostream>

#include "Action/PlayCardAction.h"
#include "Hand.h"


namespace mtg {

	Hand::Hand() {
		this->m_MaxSize = 7;
	}


	Hand::~Hand() {
	}

	void Hand::addCard(std::shared_ptr<card::CardInstance> card) {
		this->m_Cards.push_back(move(card));
	}

	std::shared_ptr<card::CardInstance> Hand::removeCard(std::shared_ptr<const card::CardInstance> card) {
		auto it = std::find(this->m_Cards.begin(), this->m_Cards.end(), card);

		if (it == this->m_Cards.end()) {
			throw - 1;
		}

		std::shared_ptr<card::CardInstance> result = *it;
		this->m_Cards.erase(it);

		return result;
	}

	std::ostream& operator<< (std::ostream& stream, const Hand& hand) {
		for (const std::shared_ptr<card::CardInstance>& card : hand.m_Cards) {
			stream << *card;
		}

		return stream;
	}

	const std::vector<std::shared_ptr<action::ActionBase>> Hand::getPlayableCards(const unsigned char playerIdx, const Mana mana) const {
		std::vector<std::shared_ptr<action::ActionBase>> result;

		for (const std::shared_ptr<card::CardInstance> card : this->m_Cards) {
			if (card->isAffordable(mana)) {
				result.push_back(std::make_shared<action::PlayCardAction>(playerIdx, card));
			}
		}

		return result;
	}

	std::unique_ptr<Matrix<unsigned char, card::CardInstance::VECTOR_SIZE>> Hand::vectorize(unsigned char playerIdx) const {
		std::unique_ptr<Matrix<unsigned char, card::CardInstance::VECTOR_SIZE>> result = std::make_unique<Matrix<unsigned char, card::CardInstance::VECTOR_SIZE>>();

		for (const std::shared_ptr<card::CardInstance>& card : this->m_Cards) {
			std::array<unsigned char, card::CardInstance::VECTOR_SIZE> cardVector = card->vectorize(false, playerIdx);
			result->put(cardVector);
		}

		return result;
	}

}
