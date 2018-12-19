#include "pch.h"
#include "CardManager.h"

namespace MTG {

	CardManager::CardManager () {

	}


	CardManager::~CardManager () {}

	std::shared_ptr<Card> CardManager::addCardFromFile(std::string filename) {
		std::shared_ptr<Card> card = Card::cardFromFile(filename);
		this->m_Cards[card->getName()] = move(card);
		return this->m_Cards[card->getName()];
	}
}
