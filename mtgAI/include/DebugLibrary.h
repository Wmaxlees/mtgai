#pragma once
#include "Library.h"

#include <memory>
#include <vector>

namespace MTG {
	class DebugLibrary : public Library
	{
		public:
			DebugLibrary ();
			~DebugLibrary ();

			void addCard (std::shared_ptr<Card> card);

			bool empty() const override;
			void shuffle() override;
			std::shared_ptr<CardInstance> getNextCard() override;

		protected:
			std::vector<std::shared_ptr<Card>> m_Cards;
	};

}
