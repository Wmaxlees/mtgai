#pragma once
#ifndef _H_PLAYER
#define _H_PLAYER

#include <memory>
#include <vector>

#include "Board.h"
#include "Card/Instance.h"
#include "Deck/DeckBase.h"
#include "Event/ENewStep.h"
#include "Event/EventBase.h"
#include "Event/Handler.h"
#include "Hand.h"
#include "Mana.h"
#include "ManaCost.h"
#include "Matrix.h"


namespace MTG {
	class PlayerState : public Event::Handler {
	public:
		PlayerState (unsigned char startingHealth, std::unique_ptr<Deck::Instance> deck, unsigned char uniqueID);
		~PlayerState ();

    void shuffle ();
		bool drawCards (unsigned char amount);
    void untapAll ();

		std::vector<std::shared_ptr<const Card::Instance>> getInstantSpeedMoves () const;
		std::vector<std::shared_ptr<const Card::Instance>> getMainPhaseMoves () const;
		std::vector<std::shared_ptr<const Card::Instance>> getPossibleAttackers () const;
		std::vector<std::shared_ptr<const Card::Instance>> getPossibleBlockers () const;

		void playCard (std::shared_ptr<const Card::Instance> card);

		void clearMana ();

    bool isDead ();

    void handle (std::unique_ptr<Event::EventBase>& event) override;

    std::unique_ptr<Matrix<unsigned char, Card::Instance::VECTOR_SIZE>> vectorize (bool hideHand, std::size_t playerIdx) const;

	protected:
    unsigned char m_UniqueID;
		unsigned char m_Health;
    std::unique_ptr<Deck::Instance> m_Deck;
		Hand m_Hand;
		Board m_Board;
		Mana m_Mana;

    void handleGameStart ();
    void handleNewStep (Event::ENewStep& newStep);

	private:



	};
}


#endif //_H_PLAYER
