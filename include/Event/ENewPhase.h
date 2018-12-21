/**
 * @Author: W. Max Lees
 * @Date:   2018-12-21T12:19:12-07:00
 * @Email:  william.lees@nist.gov
 * @Last modified by:   W. Max Lees
 * @Last modified time: 2018-12-21T14:51:30-07:00
 */
#pragma once

#ifndef _H_EVENT_ENEWPHASE
#define _H_EVENT_ENEWPHASE

#include <memory>
#include <string>

#include "Event/EventBase.h"

namespace Event {

  class ENewPhase : public EventBase {
    public:
      explicit ENewPhase (unsigned char playerID, unsigned char phaseID);

      std::string getType () const override;

      unsigned char getPlayerID () const;
      unsigned char getPhaseID () const;

    protected:
      unsigned char m_PlayerID;
      unsigned char m_PhaseID;
  };

}

#endif //_H_EVENT_ENEWPHASE
