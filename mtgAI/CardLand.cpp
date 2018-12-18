#include "pch.h"
#include "CardLand.h"


namespace MTG {


	CardLand::CardLand () {
	}


	CardLand::~CardLand () {
	}

	void CardLand::setPower (unsigned char power) {
	}

	void CardLand::setToughness (unsigned char toughness) {
	}

	bool CardLand::isAffordable(const Mana& mana) const {
		return true;
	}

}