#pragma once

#ifndef _H_CARDINSTANCE
#define _H_CARDINSTANCE

#include <memory>

#include "Card.h"
#include "Mana.h"

namespace MTG {

	class CardInstance
	{
		public:
			CardInstance (std::shared_ptr<Card> baseCard);
			~CardInstance ();

			bool isType (unsigned char type) const;
			bool isTapped () const;
			bool isAffordable (const Mana mana) const;

      void untap ();

			const ManaCost& getCost () const;

			friend std::ostream& operator<< (std::ostream& stream, const CardInstance& card);

      std::unique_ptr<unsigned char[]> vectorize (bool onBoard) const;

		protected:
			std::shared_ptr<Card> m_BaseCard;
			bool m_Tapped;
			bool m_OnBoard;
	};

	std::ostream& operator<< (std::ostream& stream, const CardInstance& card);

}

#endif //_H_CARDINSTANCE
