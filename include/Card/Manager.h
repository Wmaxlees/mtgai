#pragma once

#ifndef _H_CARDMANAGER
#define _H_CARDMANAGER

#include <map>

#include "Card/CardBase.h"

namespace MTG {
  namespace Card {

  	class Manager
  	{
  		public:
  			Manager ();
  			~Manager ();

  			std::shared_ptr<CardBase> addCardFromFile (std::string filename);

  		protected:
  			std::map<std::string, std::shared_ptr<CardBase>> m_Cards;
  	};

  }
}

#endif //_H_CARDMANAGER
