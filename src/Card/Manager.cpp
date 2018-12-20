#include <iostream>

#include "Card/Manager.h"

namespace MTG {
  namespace Card {

  	Manager::Manager () {

  	}


  	Manager::~Manager () {}

  	std::shared_ptr<CardBase> Manager::addCardFromFile(std::string filename) {
  		std::shared_ptr<CardBase> card = CardBase::cardFromFile(filename);
  		this->m_Cards[card->getName()] = card;
  		return this->m_Cards[card->getName()];
  	}
  }
}
