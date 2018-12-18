#include "pch.h"
#include "CardCreature.h"

namespace MTG {

	CardCreature::CardCreature() {
	}


	CardCreature::~CardCreature() {
	}

	void CardCreature::setPower (unsigned char power) {
		this->m_Power = power;
	}

	void CardCreature::setToughness (unsigned char toughness) {
		this->m_Toughness = toughness;
	}

	bool CardCreature::isAffordable (const Mana& mana) const {
		return mana.contains(*this->m_Cost);
	}

}
