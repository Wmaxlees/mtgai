#include "pch.h"
#include "DebugLibrary.h"
#include "utils.h"

#include <iostream>

namespace MTG {

	DebugLibrary::DebugLibrary () {
	}


	DebugLibrary::~DebugLibrary () {
    std::cout << "Destroying DebugLibrary object." << std::endl;
	}

	shared_ptr<CardInstance> DebugLibrary::getNextCard () {
		std::shared_ptr<Card> rndCard = randomVectorElement(this->m_Cards);

		return std::make_shared<CardInstance>(rndCard);
	}

	void DebugLibrary::addCard (std::shared<Card>& card) {
		this->m_Cards.push_back(card);
	}

	bool DebugLibrary::empty() const {
		return false;
	}

	void DebugLibrary::shuffle() {

	}

}
