#pragma once

#ifndef _H_CARDMANAGER
#define _H_CARDMANAGER

#include <map>

#include "Card.h"

namespace MTG {

	class CardManager
	{
		public:
			CardManager ();
			~CardManager ();

			std::shared_ptr<Card> addCardFromFile (std::string filename);

		protected:
			std::map<std::string, std::shared_ptr<Card>> m_Cards;
	};

}

#endif //_H_CARDMANAGER
