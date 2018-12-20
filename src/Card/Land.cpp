#include "Card/Land.h"


namespace MTG {
  namespace Card {

  	Land::Land () {
  	}


  	Land::~Land () {
  	}

  	void Land::setPower (unsigned char power) {
  	}

  	void Land::setToughness (unsigned char toughness) {
  	}

  	bool Land::isAffordable(const Mana& mana) const {
  		return true;
  	}

    std::array<unsigned char, 10> Land::vectorize () const {
      // 0 type
      // 1-7 for mana cost
      // 8 power
      // 9 toughness
      std::array<unsigned char, 10> result;
      result[0] = CardBase::LAND;

      for (std::size_t idx = 1; idx < 10; ++idx) {
        result[idx] = 0;
      }

      return result;
    }

  }
}
