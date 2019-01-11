#include <algorithm>

#include "Card/Creature.h"

namespace mtg {
	namespace card {

		Creature::Creature() {
			this->m_Type = CardBase::CREATURE;
		}


		Creature::~Creature() {
		}

		void Creature::setManaTap(std::string manaString) {

		}

		void Creature::setPower(unsigned char power) {
			this->m_Power = power;
		}

		void Creature::setToughness(unsigned char toughness) {
			this->m_Toughness = toughness;
		}

		bool Creature::isAffordable(const Mana& mana) const {
			return mana.contains(this->m_Cost);
		}

		const Mana Creature::getManaTap() const {
			return Mana();
		}

		std::array<unsigned char, CardBase::VECTOR_SIZE> Creature::vectorize() const {
			// 0 type
			// 1-7 for mana cost
			// 8-13 mana provided by tapping
			// 14 power
			// 15 toughness
			std::array<unsigned char, CardBase::VECTOR_SIZE> result;
			result[0] = card::CardBase::CREATURE;

			std::array<unsigned char, ManaCost::VECTOR_SIZE> cost = this->m_Cost.vectorize();
			std::copy(cost.begin(), cost.end(), result.begin() + 1);

			for (std::size_t idx = 8; idx < 14; ++idx) {
				result[idx] = 0;
			}

			result[14] = this->m_Power;
			result[15] = this->m_Toughness;

			return result;
		}

	}
}
