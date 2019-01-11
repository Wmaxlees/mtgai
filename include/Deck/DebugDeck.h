#pragma once

#ifndef _H_DEBUGDECK
#define _H_DEBUGDECK

#include <memory>
#include <vector>

#include "Card/CardBase.h"
#include "Card/CardInstance.h"
#include "Deck/DeckBase.h"

namespace mtg {
  namespace deck {
  	class DebugDeck : public DeckBase
  	{
  		public:
  			DebugDeck ();
  			~DebugDeck ();

  			void addCard (std::shared_ptr<card::CardBase> card);

  			std::unique_ptr<DeckInstance> newInstance () const;

  		protected:
  			std::vector<std::shared_ptr<card::CardBase>> m_Cards;
  	};
  }

}

#endif //_H_DEBUGDECK
