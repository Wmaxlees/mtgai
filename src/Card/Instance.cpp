
#include "Card/Instance.h"

namespace MTG {
  namespace Card {

  	Instance::Instance (std::shared_ptr<CardBase> baseCard) {
  		this->m_BaseCard = baseCard;
  		this->m_Tapped = false;
  		this->m_OnBoard = false;
  	}


  	Instance::~Instance () {
  		this->m_BaseCard = nullptr;
  	}

  	bool Instance::isType (unsigned char type) const {
  		return this->m_BaseCard->isType(type);
  	}

  	std::ostream& operator<< (std::ostream& stream, const Instance& card) {
  		stream << *(card.m_BaseCard);

  		return stream;
  	}

  	bool Instance::isTapped () const {
  		return this->m_Tapped;
  	}

  	bool Instance::isAffordable (const Mana mana) const {
  		return this->m_BaseCard->isAffordable(mana);
  	}

  	const ManaCost Instance::getCost () const {
  		return this->m_BaseCard->getCost();
  	}

    void Instance::untap () {
      this->m_Tapped = false;
    }

    std::array<unsigned char, 12> Instance::vectorize (bool onBoard) const {
      // 0-9 base card info
      // 10 tapped
      // 11 on board
      std::array<unsigned char, 12> result;

      std::array<unsigned char, 10> baseCard = this->m_BaseCard->vectorize();
      std::copy(baseCard.begin(), baseCard.end(), result.begin());

      result[10] = this->m_Tapped ? 1 : 0;
      result[11] = onBoard ? 1 : 0;

      return result;
    }

  }
}
