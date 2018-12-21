/**
 * @Author: W. Max Lees
 * @Date:   2018-12-21T12:19:12-07:00
 * @Email:  william.lees@nist.gov
 * @Last modified by:   W. Max Lees
 * @Last modified time: 2018-12-21T12:38:12-07:00
 */
#pragma once

#ifndef _H_EVENT_EPLAYCARD
#define _H_EVENT_EPLAYCARD

#include <memory>
#include <string>

#include "Card/Instance.h"
#include "Event/EventBase.h"

namespace Event {
  
  class EPlayCard : public EventBase {
    public:
      explicit EPlayCard (unsigned char playerID, std::shared_ptr<MTG::Card::Instance> card);

      std::string getType () const override;

    protected:
      unsigned char m_PlayerID;
      std::shared_ptr<MTG::Card::Instance> m_Card;
  };

}

#endif //_H_EVENT_EPLAYCARD
