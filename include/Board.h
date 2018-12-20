#pragma once

#ifndef _H_BOARD
#define _H_BOARD

#include <vector>

#include "Card/Instance.h"
#include "Matrix.h"

namespace MTG {
	class Board {
		public:
			Board ();
			~Board ();

			void addCard (std::shared_ptr<Card::Instance> card);
      void untapAll ();

			std::vector<std::shared_ptr<const Card::Instance>> getCardsOfType(unsigned int type) const;
			std::vector<std::shared_ptr<const Card::Instance>> getCardsOfType(unsigned int type, bool onlyUntapped) const;

      std::unique_ptr<Matrix<unsigned char, Card::Instance::VECTOR_SIZE>> vectorize (std::size_t playerIdx) const;

		protected:
			std::vector<std::shared_ptr<Card::Instance>> m_Cards;
	};

}

#endif //_H_BOARD
