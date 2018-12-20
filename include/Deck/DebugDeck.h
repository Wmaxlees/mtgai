#pragma once

#ifndef _H_DEBUGDECK
#define _H_DEBUGDECK

#include <memory>
#include <vector>

#include "Card/CardBase.h"
#include "Card/Instance.h"
#include "Deck/DeckBase.h"

namespace MTG {
  namespace Deck {
  	class DebugDeck : public DeckBase
  	{
  		public:
  			DebugDeck ();
  			~DebugDeck ();

  			void addCard (std::shared_ptr<Card::CardBase> card);

  			std::unique_ptr<Instance> newInstance () const;

  		protected:
  			std::vector<std::shared_ptr<Card::CardBase>> m_Cards;
  	};
  }

}

#endif //_H_DEBUGDECK
