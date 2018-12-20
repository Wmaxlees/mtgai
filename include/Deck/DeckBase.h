#pragma once
#ifndef _H_LIBRARY
#define _H_LIBRARY

#include <memory>
#include <deque>

#include "Deck/Instance.h"

namespace MTG {
  namespace Deck {
  	class DeckBase {
  		public:
        virtual ~DeckBase() = 0;
  			virtual std::unique_ptr<Instance> newInstance () const = 0;


  	};
  }
}


#endif //_H_LIBRARY
