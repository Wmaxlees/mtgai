#pragma once

#ifndef _H_STANDARDLIBRARY
#define _H_STANDARDLIBRARY

#include <array>
#include <memory>

#include "Deck/DeckBase.h"

namespace mtg {
  namespace deck {
  	class StandardDeck : public DeckBase
  	{
  		public:
  			StandardDeck ();
  			~StandardDeck ();

  			std::unique_ptr<DeckInstance> newInstance () const;

  		protected:
  			std::array<std::shared_ptr<card::CardBase>, 60> m_Cards;
  	};
  }
}

#endif //_H_STANDARDLIBRARY
