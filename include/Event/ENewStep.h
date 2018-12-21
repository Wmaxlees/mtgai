/**
 * @Author: W. Max Lees
 * @Date:   2018-12-21T12:19:12-07:00
 * @Email:  william.lees@nist.gov
 * @Last modified by:   W. Max Lees
 * @Last modified time: 2018-12-21T13:40:01-07:00
 */
#pragma once

#ifndef _H_EVENT_ENEWSTEP
#define _H_EVENT_ENEWSTEP

#include <memory>
#include <string>

#include "Event/EventBase.h"

namespace Event {

  class ENewStep : public EventBase {
    public:
      explicit ENewStep (unsigned char playerID, unsigned char stepID);

      std::string getType () const override;

      unsigned char getPlayerID () const;

    protected:
      unsigned char m_PlayerID;
      unsigned char m_StepID;
  };

}

#endif //_H_EVENT_ENEWSTEP
