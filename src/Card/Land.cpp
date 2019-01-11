#include "Card/Land.h"


namespace mtg {
	namespace card {

		Land::Land() {
			this->m_Type = CardBase::LAND;
		}


		Land::~Land() {
		}

		void Land::setManaTap(std::string manaString) {
			this->m_Mana = Mana(manaString);
		}

		void Land::setPower(unsigned char power) {
		}

		void Land::setToughness(unsigned char toughness) {
		}

		bool Land::isAffordable(const Mana& mana) const {
			return true;
		}

		const Mana Land::getManaTap() const {
			return this->m_Mana;
		}

		std::array<unsigned char, CardBase::VECTOR_SIZE> Land::vectorize() const {
			// 0 type
			// 1-7 for mana cost
			// 8-13 mana provided by tapping
			// 14 power
			// 15 toughness
			std::array<unsigned char, CardBase::VECTOR_SIZE> result;
			result[0] = CardBase::LAND;

			for (std::size_t idx = 1; idx < 8; ++idx) {
				result[idx] = 0;
			}

			result[8] = this->m_Mana.getColorless();
			result[9] = this->m_Mana.getB();
			result[10] = this->m_Mana.getG();
			result[11] = this->m_Mana.getR();
			result[12] = this->m_Mana.getU();
			result[13] = this->m_Mana.getW();

			result[14] = 0;
			result[15] = 0;

			return result;
		}

	}
}
