
#include "Card/CardInstance.h"

namespace mtg {
	namespace card {

		CardInstance::CardInstance(std::shared_ptr<CardBase> baseCard) {
			this->m_BaseCard = baseCard;
			this->m_Tapped = false;
			this->m_OnBoard = false;
			this->m_IsAttacking = false;
			this->m_HasSummoningSickness = false;
		}


		CardInstance::~CardInstance() {
			this->m_BaseCard = nullptr;
		}

		bool CardInstance::isType(unsigned char type) const {
			return this->m_BaseCard->isType(type);
		}

		std::ostream& operator<< (std::ostream& stream, const CardInstance& card) {
			stream << *(card.m_BaseCard);

			return stream;
		}

		bool CardInstance::isTapped() const {
			return this->m_Tapped;
		}

		bool CardInstance::isAffordable(const Mana mana) const {
			return this->m_BaseCard->isAffordable(mana);
		}

		const ManaCost CardInstance::getCost() const {
			return this->m_BaseCard->getCost();
		}

		const std::string CardInstance::getName() const {
			return this->m_BaseCard->getName();
		}

		void CardInstance::untap() {
			this->m_Tapped = false;
		}

		void CardInstance::tap() {
			this->m_Tapped = true;
		}

		const Mana CardInstance::getMana() const {
			return this->m_BaseCard->getManaTap();
		}

		std::array<unsigned char, CardInstance::VECTOR_SIZE> CardInstance::vectorize(bool onBoard, unsigned char playerIdx) const {
			// 0 tapped
			// 1 on board
			// 2 player idx
			// Remaining are base card info
			std::array<unsigned char, CardInstance::VECTOR_SIZE> result;
			result[0] = this->m_Tapped ? 1 : 0;
			result[1] = onBoard ? 1 : 0;
			result[2] = playerIdx;

			std::array<unsigned char, CardBase::VECTOR_SIZE> baseCard = this->m_BaseCard->vectorize();
			std::copy(baseCard.begin(), baseCard.end(), result.begin() + 3);

			return result;
		}


		bool CardInstance::hasSummoningSickness() {
			return this->m_HasSummoningSickness;
		}

		void CardInstance::setSummoningSickness() {
			this->m_HasSummoningSickness = true;
		}

		void CardInstance::resetSummoningSickness() {
			this->m_HasSummoningSickness = false;
		}


		bool CardInstance::isAttacking() {
			return this->m_IsAttacking;
		}

		void CardInstance::setAttacking() {
			this->m_IsAttacking = true;
		}

		void CardInstance::resetAttacking() {
			this->m_IsAttacking = false;
		}

	}
}
