#pragma once
#ifndef _H_GAME
#define _H_GAME

#include <vector>

#include "Matrix.h"
#include "Player.h"

namespace MTG {

	class Game {
		public:
			Game (unsigned char playerCount, std::array<std::shared_ptr<Deck::DeckBase>, 6> decks);
			Game (unsigned char playerCount, std::array<std::shared_ptr<Deck::DeckBase>, 6> decks, bool verbose);
			~Game ();

      void step ();
		  std::unique_ptr<Matrix<unsigned char, 12>> reset ();

			static const unsigned char PHASE_BEGINNING = 0;
			static const unsigned char PHASE_UNTAP = 1;
			static const unsigned char PHASE_UPKEEP = 2;
			static const unsigned char PHASE_DRAW = 3;
			static const unsigned char PHASE_MAIN = 4;
			static const unsigned char PHASE_COMBAT = 5;
			static const unsigned char PHASE_ATTACKERS = 6;
			static const unsigned char PHASE_BLOCKERS = 7;
			static const unsigned char PHASE_DAMAGE = 8;
			static const unsigned char PHASE_MAIN_SECOND = 9;
			static const unsigned char PHASE_END = 10;
			static const unsigned char PHASE_PASS_TURN = 11;

		protected:
			unsigned char m_PlayerCount;

			unsigned char m_CurrentPlayer;
			unsigned char m_PriorityPlayer;

			unsigned char m_Phase;

      std::array<std::unique_ptr<Player>, 6> m_Players;
      std::array<std::shared_ptr<Deck::DeckBase>, 6> m_Decks;
			bool m_Verbose;

			void drawOpeningCards ();

			void nextPlayer ();

      std::unique_ptr<Matrix<unsigned char, 12>> vectorize () const;


		private:



	};
}

#endif //_H_GAME
