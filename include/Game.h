#pragma once
#ifndef _H_GAME
#define _H_GAME

#include <vector>

#include "Event/EventHandler.h"
#include "Event/EventManager.h"
#include "EnvState.h"
#include "PlayerState.h"
#include "Matrix.h"


namespace mtg {

	class Game : public event::EventHandler, std::enable_shared_from_this<event::EventHandler> {
	public:
		Game(unsigned char playerCount, std::array<std::shared_ptr<deck::DeckBase>, 6> decks);
		Game(unsigned char playerCount, std::array<std::shared_ptr<deck::DeckBase>, 6> decks, bool verbose);
		~Game();

		const std::vector<std::shared_ptr<action::ActionBase>> getCurrentMoveList();
		std::unique_ptr<EnvState> getCurrentState();
		void perform(std::shared_ptr<const action::ActionBase> action);
		void pass();
		void reset();
		void handle(std::unique_ptr<event::EventBase>& event) override;

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

		friend std::ostream& operator<< (std::ostream& stream, const Game& game);

	protected:
		unsigned char m_PlayerCount;

		unsigned char m_CurrentPlayer;
		unsigned char m_PriorityPlayer;

		unsigned char m_Phase;

		std::array<std::shared_ptr<PlayerState>, 6> m_Players;
		std::array<std::shared_ptr<deck::DeckBase>, 6> m_Decks;
		bool m_Verbose;

		event::EventManager m_EventManager;

		void advancePhase();
		void nextPlayer();

		std::vector<unsigned char> getAttackablePlayerIdxs();

		std::unique_ptr<Matrix<unsigned char, card::CardInstance::VECTOR_SIZE>> vectorize() const;


	private:



	};

	std::ostream& operator<< (std::ostream& stream, const Game& game);
}

#endif //_H_GAME
