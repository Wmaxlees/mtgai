#include "pch.h"
#include "CardInstance.h"

namespace MTG {

	CardInstance::CardInstance (Card* baseCard) {
		this->m_BaseCard = baseCard;
		this->m_Tapped = false;
		this->m_OnBoard = false;
	}


	CardInstance::~CardInstance () {
		this->m_BaseCard = nullptr;
	}

	bool CardInstance::isType (unsigned char type) const {
		return this->m_BaseCard->isType(type);
	}

	std::ostream& operator<< (std::ostream& stream, const CardInstance& card) {
		stream << *(card.m_BaseCard);

		return stream;
	}

	bool CardInstance::isOnBoard () const {
		return this->m_OnBoard;
	}

	bool CardInstance::isTapped () const {
		return this->m_Tapped;
	}

	bool CardInstance::isAffordable (const Mana mana) const {
		return this->m_BaseCard->isAffordable(mana);
	}

	const ManaCost& CardInstance::getCost () const {
		return *this->m_BaseCard->getCost();
	}

}