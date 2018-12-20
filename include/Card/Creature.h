#pragma once

#ifndef _H_CARDCREATURE
#define _H_CARDCREATURE

#include <memory>

#include "Card/CardBase.h"
#include "Mana.h"

namespace MTG {
  namespace Card {

  	class Creature : public CardBase
  	{
  		public:
  			Creature ();
  			~Creature ();

  			bool isAffordable (const Mana& mana) const override;

  			void setPower (unsigned char power) override;
  			void setToughness (unsigned char toughness) override;

        std::array<unsigned char, 10> vectorize () const override;

  		protected:
  			unsigned char m_Power;
  			unsigned char m_Toughness;
  	};

  }

}

#endif //_H_CARDCREATURE
