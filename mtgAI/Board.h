#pragma once

#ifndef _H_BOARD
#define _H_BOARD

#include <vector>

#include "CardInstance.h"

namespace MTG {
	class Board {
		public:
			Board ();
			~Board ();

			void addCard (CardInstance* card);

			std::vector<const CardInstance*> getCardsOfType(unsigned int type) const;
			std::vector<const CardInstance*> getCardsOfType(unsigned int type, bool onlyUntapped) const;

		protected:
			std::vector<CardInstance*> m_Cards;
	};

}

#endif //_H_BOARD
