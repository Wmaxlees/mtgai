#pragma once
#ifndef _H_PLAYER
#define _H_PLAYER

#include <memory>
#include <vector>

#include "Board.h"
#include "Card/Instance.h"
#include "Deck/DeckBase.h"
#include "Hand.h"
#include "Mana.h"
#include "ManaCost.h"
#include "Matrix.h"


namespace MTG {
	class Player {
	public:
		Player (unsigned char startingHealth, std::unique_ptr<Deck::Instance> deck);
		~Player ();

    void shuffle ();
		bool drawCards (unsigned char amount);
    void untapAll ();

		void printHand () const;

		std::vector<std::shared_ptr<const Card::Instance>> getInstantSpeedMoves () const;
		std::vector<std::shared_ptr<const Card::Instance>> getMainPhaseMoves () const;
		std::vector<std::shared_ptr<const Card::Instance>> getPossibleAttackers () const;
		std::vector<std::shared_ptr<const Card::Instance>> getPossibleBlockers () const;

		void playCard (std::shared_ptr<const Card::Instance> card);

		void clearMana ();

    bool isDead ();

    std::unique_ptr<Matrix<unsigned char, Card::Instance::VECTOR_SIZE>> vectorize (bool hideHand, std::size_t playerIdx) const;

	protected:
		unsigned char m_Health;
    std::unique_ptr<Deck::Instance> m_Deck;
		Hand m_Hand;
		Board m_Board;
		Mana m_Mana;

	private:



	};
}


#endif //_H_PLAYER
