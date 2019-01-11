#pragma once

#ifndef _H_CARDINSTANCE
#define _H_CARDINSTANCE

#include <memory>

#include "Card/CardBase.h"
#include "Mana.h"

namespace mtg {
	namespace card {
		class CardInstance
		{
		public:
			static const std::size_t VECTOR_SIZE = CardBase::VECTOR_SIZE + 3;

			CardInstance(std::shared_ptr<CardBase> baseCard);
			~CardInstance();

			bool isType(unsigned char type) const;
			bool isTapped() const;
			bool isAffordable(const Mana mana) const;

			const Mana getMana() const;

			void untap();
			void tap();

			bool hasSummoningSickness();
			void setSummoningSickness();
			void resetSummoningSickness();

			bool isAttacking();
			void setAttacking();
			void resetAttacking();

			const ManaCost getCost() const;
			const std::string getName() const;

			friend std::ostream& operator<< (std::ostream& stream, const CardInstance& card);

			std::array<unsigned char, VECTOR_SIZE> vectorize(bool onBoard, unsigned char playerIdx) const;

		protected:
			std::shared_ptr<CardBase> m_BaseCard;
			bool m_Tapped;
			bool m_OnBoard;
			bool m_IsAttacking;
			bool m_HasSummoningSickness;
		};

		std::ostream& operator<< (std::ostream& stream, const CardInstance& card);

	}
}

#endif //_H_CARDINSTANCE
