/**
 * @Author: W. Max Lees
 * @Date:   2018-12-21T12:19:12-07:00
 * @Email:  william.lees@nist.gov
 * @Last modified by:   W. Max Lees
 * @Last modified time: 2018-12-21T12:58:13-07:00
 */
#pragma once

#ifndef _H_EVENT_EGAMESTART
#define _H_EVENT_EGAMESTART

#include <memory>
#include <string>

#include "Event/EventBase.h"

namespace Event {

  class EGameStart : public EventBase {
    public:
      explicit EGameStart ();

      std::string getType () const override;

    protected:
      unsigned char m_PlayerID;
      unsigned char m_StepID;
  };

}

#endif //_H_EVENT_EGAMESTART
