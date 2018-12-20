#pragma once

#ifndef _H_STANDARDLIBRARY
#define _H_STANDARDLIBRARY

#include <array>
#include <memory>

#include "Deck/DeckBase.h"

namespace MTG {
  namespace Deck {
  	class StandardDeck : public DeckBase
  	{
  		public:
  			StandardDeck ();
  			~StandardDeck ();

  			std::unique_ptr<Instance> newInstance () const;

  		protected:
  			std::array<std::shared_ptr<Card::CardBase>, 60> m_Cards;
  	};
  }
}

#endif //_H_STANDARDLIBRARY
