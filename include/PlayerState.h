#pragma once
#ifndef _H_PLAYER
#define _H_PLAYER

#include <memory>
#include <iostream>
#include <vector>

#include "Action/ActionBase.h"
#include "Board.h"
#include "Card/CardInstance.h"
#include "Deck/DeckBase.h"
#include "Event/NewPhaseEvent.h"
#include "Event/EventBase.h"
#include "Event/EventHandler.h"
#include "Hand.h"
#include "Mana.h"
#include "ManaCost.h"
#include "Matrix.h"


namespace mtg {
	class PlayerState : public event::EventHandler {
	public:
		PlayerState(unsigned char startingHealth, std::unique_ptr<deck::DeckInstance> deck, unsigned char uniqueID);
		~PlayerState();

		const std::vector<std::shared_ptr<action::ActionBase>> getInstantSpeedMoves() const;
		const std::vector<std::shared_ptr<action::ActionBase>> getMainPhaseMoves() const;
		const std::vector<std::shared_ptr<action::ActionBase>> getPossibleBlockers() const;
		const std::vector<std::shared_ptr<action::ActionBase>> getDeclareAttackerMoves(unsigned char targetIdx) const;

		bool isDead();

		void handle(std::unique_ptr<event::EventBase>& event) override;

		std::unique_ptr<Matrix<unsigned char, card::CardInstance::VECTOR_SIZE>> vectorize(bool hideHand, unsigned char playerIdx) const;

		friend std::ostream& operator<< (std::ostream& stream, const PlayerState& player);

	protected:
		unsigned char m_UniqueID;
		unsigned char m_Health;
		std::unique_ptr<deck::DeckInstance> m_Deck;
		Hand m_Hand;
		Board m_Board;
		Mana m_Mana;

		void handleGameStart();
		void handleNewPhase(event::NewPhaseEvent& newPhase);

		bool drawCards(unsigned char amount);
		void playCard(std::shared_ptr<const card::CardInstance> card);
		void tapLand(std::shared_ptr<card::CardInstance> card);

	private:



	};

	std::ostream& operator<< (std::ostream& stream, const PlayerState& player);
}


#endif //_H_PLAYER
