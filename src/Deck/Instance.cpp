/**
 * @Author: W. Max Lees
 * @Date:   2018-12-19T13:03:50-07:00
 * @Email:  william.lees@nist.gov
 * @Last modified by:   W. Max Lees
 * @Last modified time: 2018-12-19T13:24:24-07:00
 */

#include <algorithm>

#include "Deck/Instance.h"

namespace MTG {
  namespace Deck {

    Instance::Instance (std::deque<std::shared_ptr<Card::CardBase>> deck) : m_Cards(deck) {}


    bool Instance::empty() const {
      return this->m_Cards.empty();
    }


    void Instance::shuffle () {
      std::random_shuffle(this->m_Cards.begin(), this->m_Cards.end());
    }


    std::shared_ptr<Card::Instance> Instance::getNextCard () {
      std::shared_ptr<Card::Instance> result = std::make_shared<Card::Instance>(this->m_Cards.front());
      this->m_Cards.pop_front();
      return result;
    }

  }
}
