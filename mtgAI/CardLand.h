#pragma once
#include "Card.h"

namespace MTG {
	class CardLand : public Card {
		public:
			CardLand ();
			~CardLand ();

			bool isAffordable(const Mana& mana) const override;

			void setPower(unsigned char power) override;
			void setToughness(unsigned char toughness) override;

		protected:
			unsigned char m_LandColorless;
			unsigned char m_LandB;
			unsigned char m_LandG;
			unsigned char m_LandR;
			unsigned char m_LandU;
			unsigned char m_LandW;
	};
}

