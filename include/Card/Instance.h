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
        static const std::size_t VECTOR_SIZE = CardBase::VECTOR_SIZE + 3;

  			Instance (std::shared_ptr<CardBase> baseCard);
  			~Instance ();

  			bool isType (unsigned char type) const;
  			bool isTapped () const;
  			bool isAffordable (const Mana mana) const;

        void untap ();

  			const ManaCost getCost () const;
        const std::string getName () const;

  			friend std::ostream& operator<< (std::ostream& stream, const Instance& card);

        std::array<unsigned char, VECTOR_SIZE> vectorize (bool onBoard, std::size_t playerIdx) const;

  		protected:
  			std::shared_ptr<CardBase> m_BaseCard;
  			bool m_Tapped;
  			bool m_OnBoard;
  	};

  	std::ostream& operator<< (std::ostream& stream, const Instance& card);

  }
}

#endif //_H_CARDINSTANCE
