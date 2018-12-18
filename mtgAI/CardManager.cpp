#include "pch.h"
#include "CardManager.h"

namespace MTG {

	CardManager::CardManager () {

	}


	CardManager::~CardManager () {
		for (std::map<std::string, Card*>::value_type& x : this->m_Cards) {
			delete x.second;
			x.second = nullptr;
		}
	}

	Card* CardManager::addCardFromFile(std::string filename) {
		Card* card = Card::cardFromFile(filename);
		this->m_Cards[card->getName()] = card;
		return card;
	}
}
