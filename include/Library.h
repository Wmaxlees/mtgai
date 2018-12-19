#pragma once
#ifndef _H_LIBRARY
#define _H_LIBRARY

#include <memory>
#include <deque>

#include "CardInstance.h"

namespace MTG {
	class Library {
		public:
      virtual ~Library() = 0;
			virtual bool empty () const = 0;
			virtual std::shared_ptr<CardInstance> getNextCard () = 0;
			virtual void shuffle () = 0;


	};
}


#endif //_H_LIBRARY
