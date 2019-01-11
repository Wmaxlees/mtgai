#pragma once
#ifndef _H_HAND
#define _H_HAND

#include "Action/ActionBase.h"
#include "Card/CardInstance.h"
#include "Mana.h"
#include "Matrix.h"

#include <memory>
#include <vector>

namespace mtg {

	class Hand {
	public:
		Hand();
		~Hand();

		void addCard(std::shared_ptr<card::CardInstance> card);
		std::shared_ptr<card::CardInstance> removeCard(std::shared_ptr<const card::CardInstance> card);

		const std::vector<std::shared_ptr<action::ActionBase>> getPlayableCards(const unsigned char playerIdx, const Mana mana) const;

		std::unique_ptr<Matrix<unsigned char, card::CardInstance::VECTOR_SIZE>> vectorize(unsigned char playerIdx) const;

		friend std::ostream& operator<< (std::ostream& stream, const Hand& hand);

	protected:
		unsigned char m_MaxSize;
		std::vector<std::shared_ptr<card::CardInstance>> m_Cards;

	private:


	};

	std::ostream& operator<< (std::ostream& stream, const Hand& hand);
}

#endif //_H_HAND
