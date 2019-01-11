
#pragma once

#ifndef _H_DECKINSTANCE
#define _H_DECKINSTANCE

#include "Card/CardBase.h"
#include "Card/CardInstance.h"

#include <deque>
#include <memory>

namespace mtg {
  namespace deck {

    class DeckInstance {
		public:
			bool empty () const;
  			std::shared_ptr<card::CardInstance> getNextCard ();
  			void shuffle ();

			DeckInstance (std::deque<std::shared_ptr<card::CardBase>> deck);

		protected:
			std::deque<std::shared_ptr<card::CardBase>> m_Cards;

      private:


    };

  }
}

#endif //_H_DECKINSTANCE
