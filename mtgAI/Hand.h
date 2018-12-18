#pragma once
#ifndef _H_HAND
#define _H_HAND

#include "CardInstance.h"
#include "Mana.h"

#include <vector>

namespace MTG {
	class Hand {
		public:
			Hand ();
			~Hand ();

			void addCard (CardInstance* card);
			void removeCard (CardInstance* card);

			std::vector<const CardInstance*> getPlayableCards(const Mana mana) const;

			friend std::ostream& operator<< (std::ostream& stream, const Hand& hand);

		protected:
			unsigned char m_MaxSize;
			std::vector<CardInstance*> m_Cards;

		private:

		
	};

	std::ostream& operator<< (std::ostream& stream, const MTG::Hand& hand);
}

#endif //_H_HAND
