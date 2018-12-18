#pragma once
#include "Library.h"

#include <vector>

namespace MTG {
	class DebugLibrary : public Library
	{
		public:
			DebugLibrary ();
			~DebugLibrary ();

			void addCard (Card* card);

			bool empty() const override;
			void shuffle() override;
			CardInstance* getNextCard() override;

		protected:
			std::vector<Card*> m_Cards;
	};

}