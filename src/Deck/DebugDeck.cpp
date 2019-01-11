#include <iostream>

#include "Deck/DebugDeck.h"
#include "utils.h"

namespace mtg {
  namespace deck {

  	DebugDeck::DebugDeck () {
  	}


  	DebugDeck::~DebugDeck () {
      std::cout << "Destroying DebugDeck object." << std::endl;
  	}

  	void DebugDeck::addCard (std::shared_ptr<card::CardBase> card) {
  		this->m_Cards.push_back(card);
  	}

    std::unique_ptr<DeckInstance> DebugDeck::newInstance () const {
      std::deque<std::shared_ptr<card::CardBase>> cards;

      for (std::shared_ptr<card::CardBase> card : this->m_Cards) {
        for (std::size_t idx = 0; idx < 30; ++idx) {
          cards.push_back(card);
        }
      }

      std::unique_ptr<DeckInstance> result = std::make_unique<DeckInstance>(cards);
      return move(result);
    }

  }
}
