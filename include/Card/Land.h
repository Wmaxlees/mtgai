#pragma once

#include "Card/CardBase.h"
#include "Mana.h"

namespace mtg {
	namespace card {
		class Land : public CardBase {
		public:
			Land();
			~Land();

			bool isAffordable(const Mana& mana) const override;

			void setManaTap(std::string manaString) override;
			void setPower(unsigned char power) override;
			void setToughness(unsigned char toughness) override;

			const Mana getManaTap() const override;

			std::array<unsigned char, CardBase::VECTOR_SIZE> vectorize() const override;

		protected:
			mtg::Mana m_Mana;
		};
	}
}
