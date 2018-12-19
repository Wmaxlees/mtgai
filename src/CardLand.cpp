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

  std::unique_ptr<unsigned char[]> CardLand::vectorize () const {
    // 0 type
    // 1-7 for mana cost
    // 8 power
    // 9 toughness
    std::unique_ptr<unsigned char[]> result = std::make_unique<unsigned char[]>(10);

    result[0] = Card::LAND;

    for (std::size_t idx = 1; idx < 10; ++idx) {
      result[idx] = 0;
    }

    return result;
  }


}
