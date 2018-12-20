#include <iostream>

#include "Deck/DebugDeck.h"
#include "utils.h"

namespace MTG {
  namespace Deck {

  	DebugDeck::DebugDeck () {
  	}


  	DebugDeck::~DebugDeck () {
      std::cout << "Destroying DebugDeck object." << std::endl;
  	}

  	void DebugDeck::addCard (std::shared_ptr<Card::CardBase> card) {
  		this->m_Cards.push_back(card);
  	}

    std::unique_ptr<Instance> DebugDeck::newInstance () const {
      std::deque<std::shared_ptr<Card::CardBase>> cards;

      for (std::shared_ptr<Card::CardBase> card : this->m_Cards) {
        for (std::size_t idx = 0; idx < 30; ++idx) {
          cards.push_back(card);
        }
      }

      std::unique_ptr<Instance> result = std::make_unique<Instance>(cards);
      return move(result);
    }

  }
}
