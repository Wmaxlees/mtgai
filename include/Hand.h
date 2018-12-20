#pragma once
#ifndef _H_HAND
#define _H_HAND

#include "Card/Instance.h"
#include "Mana.h"
#include "Matrix.h"

#include <memory>
#include <vector>

namespace MTG {
	class Hand {
		public:
			Hand ();
			~Hand ();

			void addCard (std::shared_ptr<Card::Instance> card);
			std::shared_ptr<Card::Instance> removeCard (std::shared_ptr<const Card::Instance> card);

			std::vector<std::shared_ptr<const Card::Instance>> getPlayableCards(const Mana mana) const;

      std::unique_ptr<Matrix<unsigned char, Card::Instance::VECTOR_SIZE>> vectorize (std::size_t playerIdx) const;

			friend std::ostream& operator<< (std::ostream& stream, const Hand& hand);

		protected:
			unsigned char m_MaxSize;
			std::vector<std::shared_ptr<Card::Instance>> m_Cards;

		private:


	};

	std::ostream& operator<< (std::ostream& stream, const MTG::Hand& hand);
}

#endif //_H_HAND
