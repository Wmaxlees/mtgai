#include <algorithm>

#include "Deck/StandardDeck.h"

namespace MTG {
  namespace Deck {

  	StandardDeck::StandardDeck () {
  		this->m_Cards = std::array<std::shared_ptr<Card::CardBase>, 60>();
  	}


  	StandardDeck::~StandardDeck () {
  	}

    std::unique_ptr<Instance> StandardDeck::newInstance () const {
      std::deque<std::shared_ptr<Card::CardBase>> cards;

      std::copy(this->m_Cards.begin(), this->m_Cards.end(), cards.begin());

      std::unique_ptr<Instance> result = std::make_unique<Instance>(cards);
      return move(result);
    }

  }
}
