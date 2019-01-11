#pragma once
#ifndef _H_LIBRARY
#define _H_LIBRARY

#include <memory>
#include <deque>

#include "Deck/DeckInstance.h"

namespace mtg {
  namespace deck {
  	class DeckBase {
  		public:
        virtual ~DeckBase() = 0;
  			virtual std::unique_ptr<DeckInstance> newInstance () const = 0;


  	};
  }
}


#endif //_H_LIBRARY
