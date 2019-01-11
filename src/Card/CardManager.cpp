#include <iostream>

#include "Card/CardManager.h"

namespace mtg {
  namespace card {

  	CardManager::CardManager () {

  	}


  	CardManager::~CardManager () {}

  	std::shared_ptr<CardBase> CardManager::addCardFromFile (std::string filename) {
  		std::shared_ptr<CardBase> card = CardBase::cardFromFile(filename);
  		this->m_Cards[card->getName()] = card;
  		return this->m_Cards[card->getName()];
  	}
  }
}
