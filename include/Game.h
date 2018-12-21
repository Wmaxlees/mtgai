#pragma once
#ifndef _H_GAME
#define _H_GAME

#include <vector>

#include "Event/Handler.h"
#include "Event/Manager.h"
#include "EnvState.h"
#include "PlayerState.h"
#include "Matrix.h"


namespace MTG {

	class Game : public Event::Handler, std::enable_shared_from_this<Event::Handler> {
		public:
			Game (unsigned char playerCount, std::array<std::shared_ptr<Deck::DeckBase>, 6> decks);
			Game (unsigned char playerCount, std::array<std::shared_ptr<Deck::DeckBase>, 6> decks, bool verbose);
			~Game ();

      std::vector<std::shared_ptr<const Card::Instance>> getCurrentMoveList ();
      std::unique_ptr<EnvState> getCurrentState();
      void perform (std::shared_ptr<const Card::Instance> card);
      void pass ();
		  void reset ();
      void handle (std::unique_ptr<Event::EventBase>& event) override;

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

      std::array<std::shared_ptr<PlayerState>, 6> m_Players;
      std::array<std::shared_ptr<Deck::DeckBase>, 6> m_Decks;
			bool m_Verbose;

      Event::Manager m_EventManager;

      void advancePhase ();
			void nextPlayer ();

      std::unique_ptr<Matrix<unsigned char, Card::Instance::VECTOR_SIZE>> vectorize () const;


		private:



	};
}

#endif //_H_GAME
