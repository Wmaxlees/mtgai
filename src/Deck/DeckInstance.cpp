/**
 * @Author: W. Max Lees
 * @Date:   2018-12-19T13:03:50-07:00
 * @Email:  william.lees@nist.gov
 * @Last modified by:   W. Max Lees
 * @Last modified time: 2018-12-19T13:24:24-07:00
 */

#include <algorithm>
#include <random>

#include "Deck/DeckInstance.h"

namespace mtg {
	namespace deck {

		DeckInstance::DeckInstance(std::deque<std::shared_ptr<card::CardBase>> deck) : m_Cards(deck) {}


		bool DeckInstance::empty() const {
			return this->m_Cards.empty();
		}


		void DeckInstance::shuffle() {
			std::random_device rd;
			std::mt19937 g(rd());

			std::shuffle(this->m_Cards.begin(), this->m_Cards.end(), g);
		}


		std::shared_ptr<card::CardInstance> DeckInstance::getNextCard() {
			std::shared_ptr<card::CardInstance> result = std::make_shared<card::CardInstance>(this->m_Cards.front());
			this->m_Cards.pop_front();
			return result;
		}

	}
}
