#pragma once

#ifndef _H_CARDINSTANCE
#define _H_CARDINSTANCE

#include <memory>

#include "Card/CardBase.h"
#include "Mana.h"

namespace MTG {
  namespace Card {
  	class Instance
  	{
  		public:
  			Instance (std::shared_ptr<CardBase> baseCard);
  			~Instance ();

  			bool isType (unsigned char type) const;
  			bool isTapped () const;
  			bool isAffordable (const Mana mana) const;

        void untap ();

  			const ManaCost getCost () const;

  			friend std::ostream& operator<< (std::ostream& stream, const Instance& card);

        std::array<unsigned char, 12> vectorize (bool onBoard) const;

  		protected:
  			std::shared_ptr<CardBase> m_BaseCard;
  			bool m_Tapped;
  			bool m_OnBoard;
  	};

  	std::ostream& operator<< (std::ostream& stream, const Instance& card);

  }
}

#endif //_H_CARDINSTANCE
