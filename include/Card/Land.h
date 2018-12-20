#pragma once
#include "Card/CardBase.h"

namespace MTG {
  namespace Card {
  	class Land : public CardBase {
  		public:
  			Land ();
  			~Land ();

  			bool isAffordable(const Mana& mana) const override;

  			void setPower(unsigned char power) override;
  			void setToughness(unsigned char toughness) override;

        std::array<unsigned char, 10> vectorize () const override;

  		protected:
  			unsigned char m_LandColorless;
  			unsigned char m_LandB;
  			unsigned char m_LandG;
  			unsigned char m_LandR;
  			unsigned char m_LandU;
  			unsigned char m_LandW;
  	};
  }
}
