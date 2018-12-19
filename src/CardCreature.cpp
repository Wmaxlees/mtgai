#include "pch.h"
#include "CardCreature.h"

#include <algorithm>

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

  std::unique_ptr<unsigned char[]> CardCreature::vectorize () const {
    // 0 type
    // 1-7 for mana cost
    // 8 power
    // 9 toughness
    std::unique_ptr<unsigned char[]> result = std::make_unique<unsigned char[]>(10);

    result[0] = Card::CREATURE;

    std::unique_ptr<unsigned char[]> cost = this->m_Cost->vectorize();
    std::copy(&(cost[0]), &(cost[7]), &(result[1]));

    result[7] = this->m_Power;
    result[8] = this->m_Toughness;

    return result;
  }

}
