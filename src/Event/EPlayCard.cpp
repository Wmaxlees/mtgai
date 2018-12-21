/**
 * @Author: W. Max Lees
 * @Date:   2018-12-21T12:18:59-07:00
 * @Email:  william.lees@nist.gov
 * @Last modified by:   W. Max Lees
 * @Last modified time: 2018-12-21T12:34:11-07:00
 */
#include "Event/EPlayCard.h"

namespace Event {
  EPlayCard::EPlayCard (unsigned char playerID, std::shared_ptr<MTG::Card::Instance> card) {
    this->m_PlayerID = playerID;
    this->m_Card = card;
  }

  std::string EPlayCard::getType () const {
    return "PlayCard";
  }
}
