#include "pch.h"
#include "DebugLibrary.h"
#include "utils.h"

namespace MTG {

	DebugLibrary::DebugLibrary () {
	}


	DebugLibrary::~DebugLibrary () {
	}

	CardInstance* DebugLibrary::getNextCard () {
		Card* rndCard = randomVectorElement(this->m_Cards);

		return new CardInstance(rndCard);
	}

	void DebugLibrary::addCard (Card* card) {
		this->m_Cards.push_back(card);
	}

	bool DebugLibrary::empty() const {
		return false;
	}

	void DebugLibrary::shuffle() {

	}

}
