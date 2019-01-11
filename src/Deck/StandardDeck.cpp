#include <algorithm>

#include "Deck/StandardDeck.h"

namespace mtg {
  namespace deck {

  	StandardDeck::StandardDeck () {
  		this->m_Cards = std::array<std::shared_ptr<card::CardBase>, 60>();
  	}


  	StandardDeck::~StandardDeck () {
  	}

    std::unique_ptr<DeckInstance> StandardDeck::newInstance () const {
      std::deque<std::shared_ptr<card::CardBase>> cards;

      std::copy(this->m_Cards.begin(), this->m_Cards.end(), cards.begin());

      std::unique_ptr<DeckInstance> result = std::make_unique<DeckInstance>(cards);
      return move(result);
    }

  }
}
