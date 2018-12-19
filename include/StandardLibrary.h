#pragma once
#include "Library.h"

namespace MTG {
	class StandardLibrary : public Library
	{
		public:
			StandardLibrary ();
			~StandardLibrary ();

			bool empty () const override;
			void shuffle () override;
			CardInstance* getNextCard () override;

		protected:
			std::deque<CardInstance*> m_Cards;
	};

}

