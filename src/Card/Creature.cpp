
#include "Card/Creature.h"

#include <algorithm>

namespace MTG {
  namespace Card {

  	Creature::Creature() {
  	}


  	Creature::~Creature() {
  	}

  	void Creature::setPower (unsigned char power) {
  		this->m_Power = power;
  	}

  	void Creature::setToughness (unsigned char toughness) {
  		this->m_Toughness = toughness;
  	}

  	bool Creature::isAffordable (const Mana& mana) const {
  		return mana.contains(this->m_Cost);
  	}

    std::array<unsigned char, 10> Creature::vectorize () const {
      // 0 type
      // 1-7 for mana cost
      // 8 power
      // 9 toughness
      std::array<unsigned char, 10> result;
      result[0] = Card::CardBase::CREATURE;

      std::array<unsigned char, 7> cost = this->m_Cost.vectorize();
      std::copy(cost.begin(), cost.end(), result.begin()+1);

      result[8] = this->m_Power;
      result[9] = this->m_Toughness;

      return result;
    }

  }
}
