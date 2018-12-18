#pragma once

#ifndef _H_CARDINSTANCE
#define _H_CARDINSTANCE

#include "Card.h"
#include "Mana.h"

namespace MTG {

	class CardInstance
	{
		public:
			CardInstance (Card* baseCard);
			~CardInstance ();

			bool isType (unsigned char type) const;
			bool isOnBoard () const;
			bool isTapped () const;
			bool isAffordable (const Mana mana) const;

			const ManaCost& getCost () const;

			friend std::ostream& operator<< (std::ostream& stream, const CardInstance& card);

		protected:
			Card* m_BaseCard;
			bool m_Tapped;
			bool m_OnBoard;
	};

	std::ostream& operator<< (std::ostream& stream, const CardInstance& card);

}

#endif //_H_CARDINSTANCE
