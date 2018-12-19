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

	bool CardInstance::isTapped () const {
		return this->m_Tapped;
	}

	bool CardInstance::isAffordable (const Mana mana) const {
		return this->m_BaseCard->isAffordable(mana);
	}

	const ManaCost& CardInstance::getCost () const {
		return *this->m_BaseCard->getCost();
	}

  void CardInstance::untap () {
    this->m_Tapped = false;
  }

  std::unique_ptr<unsigned char[]> CardInstance::vectorize (bool onBoard) const {
    // 0-9 base card info
    // 10 tapped
    // 11 on board
    std::unique_ptr<unsigned char[]> result = std::make_unique<unsigned char[]>(12);

    std::unique_ptr<unsigned char[]> baseCard = this->m_BaseCard->vectorize();
    std::copy(&(baseCard[0]), &(baseCard[12]), &(result[0]));

    result[10] = this->m_Tapped ? 0 : 1;
    result[11] = onBoard ? 0 : 1;

    return result;
  }

}
