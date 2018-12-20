
#pragma once

#ifndef _H_DECKINSTANCE
#define _H_DECKINSTANCE

#include "Card/CardBase.h"
#include "Card/Instance.h"

#include <deque>
#include <memory>

namespace MTG {
  namespace Deck {

    class Instance {
      public:
        bool empty () const;
  		  std::shared_ptr<Card::Instance> getNextCard ();
  			void shuffle ();

        Instance (std::deque<std::shared_ptr<Card::CardBase>> deck);

      protected:
        std::deque<std::shared_ptr<Card::CardBase>> m_Cards;

      private:


    };

  }
}

#endif //_H_DECKINSTANCE
