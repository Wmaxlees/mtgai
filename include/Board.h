#pragma once

#ifndef _H_BOARD
#define _H_BOARD

#include <vector>

#include "Action/ActionBase.h"
#include "Card/CardInstance.h"
#include "Matrix.h"

namespace mtg {
	class Board {
	public:
		Board();
		~Board();

		void addCard(std::shared_ptr<card::CardInstance> card);
		void untapAll();

		std::vector<std::shared_ptr<const card::CardInstance>> getCardsOfType(unsigned int type) const;
		std::vector<std::shared_ptr<const card::CardInstance>> getCardsOfType(unsigned int type, bool onlyUntapped) const;

		void removeAllSummoningSickness();

		std::unique_ptr<Matrix<unsigned char, card::CardInstance::VECTOR_SIZE>> vectorize(unsigned char playerIdx) const;

		const std::vector<std::shared_ptr<action::ActionBase>> getPlayableAbilities(unsigned char playerIdx, const Mana mana) const;
		const std::vector<std::shared_ptr<action::ActionBase>> getTappableLands(unsigned char playerIdx) const;
		const std::vector<std::shared_ptr<action::ActionBase>> getDeclareAttackerMoves(unsigned char playerIdx, unsigned char targetIdx) const;

		friend std::ostream& operator<< (std::ostream& stream, const Board& board);

	protected:
		std::vector<std::shared_ptr<card::CardInstance>> m_Cards;
	};


	std::ostream& operator<< (std::ostream& stream, const Board& board);
}

#endif //_H_BOARD
