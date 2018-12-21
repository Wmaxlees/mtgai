
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

    const std::string Instance::getName () const {
      return this->m_BaseCard->getName();
    }

    void Instance::untap () {
      this->m_Tapped = false;
    }

    std::array<unsigned char, Instance::VECTOR_SIZE> Instance::vectorize (bool onBoard, std::size_t playerIdx) const {
      // 0 tapped
      // 1 on board
      // 2 player idx
      // Remaining are base card info
      std::array<unsigned char, Instance::VECTOR_SIZE> result;
      result[0] = this->m_Tapped ? 1 : 0;
      result[1] = onBoard ? 1 : 0;
      result[2] = playerIdx;

      std::array<unsigned char, CardBase::VECTOR_SIZE> baseCard = this->m_BaseCard->vectorize();
      std::copy(baseCard.begin(), baseCard.end(), result.begin()+3);

      return result;
    }

  }
}
