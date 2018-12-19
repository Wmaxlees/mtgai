#pragma once
#ifndef _H_HAND
#define _H_HAND

#include "CardInstance.h"
#include "Mana.h"
#include "Matrix.h"

#include <memory>
#include <vector>

namespace MTG {
	class Hand {
		public:
			Hand ();
			~Hand ();

			void addCard (std::shared_ptr<CardInstance> card);
			void removeCard (std::shared_ptr<CardInstance> card);

			std::vector<std::shared_ptr<CardInstance>> getPlayableCards(const Mana mana) const;

      std::unique_ptr<Matrix<unsigned char>> vectorize () const;

			friend std::ostream& operator<< (std::ostream& stream, const Hand& hand);

		protected:
			unsigned char m_MaxSize;
			std::vector<std::shared_ptr<CardInstance>> m_Cards;

		private:


	};

	std::ostream& operator<< (std::ostream& stream, const MTG::Hand& hand);
}

#endif //_H_HAND
