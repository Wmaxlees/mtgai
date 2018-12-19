#pragma once

#ifndef _H_CARDCREATURE
#define _H_CARDCREATURE

#include <memory>

#include "Card.h"
#include "Mana.h"

namespace MTG {

	class CardCreature : public Card
	{
		public:
			CardCreature ();
			~CardCreature ();

			bool isAffordable (const Mana& mana) const override;

			void setPower (unsigned char power) override;
			void setToughness (unsigned char toughness) override;

      std::unique_ptr<unsigned char[]> vectorize () const override;

		protected:
			unsigned char m_Power;
			unsigned char m_Toughness;
	};

}

#endif //_H_CARDCREATURE
