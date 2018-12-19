#pragma once
#ifndef _H_PLAYER
#define _H_PLAYER

#include <vector>

#include "Hand.h"
#include "Library.h"
#include "ManaCost.h"
#include "Board.h"
#include "Mana.h"
#include "Matrix.h"


namespace MTG {
	class Player {
	public:
		Player (unsigned char startingHealth, Library* library);
		~Player ();

		bool drawCards (unsigned char amount);
    void untapAll ();

		void printHand () const;

		std::vector<const CardInstance*> getInstantSpeedMoves () const;
		std::vector<const CardInstance*> getMainPhaseMoves () const;
		std::vector<const CardInstance*> getPossibleAttackers () const;
		std::vector<const CardInstance*> getPossibleBlockers () const;

		void playCard (const CardInstance*);

		void clearMana ();

    Matrix<unsigned char>* vectorize () const;

	protected:
		unsigned char m_Health;
		Library* m_Library;
		Hand m_Hand;
		Board m_Board;
		Mana m_Mana;

	private:



	};
}


#endif //_H_PLAYER
