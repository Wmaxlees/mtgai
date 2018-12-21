/**
 * @Author: W. Max Lees
 * @Date:   2018-12-21T11:24:02-07:00
 * @Email:  william.lees@nist.gov
 * @Last modified by:   W. Max Lees
 * @Last modified time: 2018-12-21T12:05:12-07:00
 */

#pragma once

#ifndef _H_EVENT_HANDLER
#define _H_EVENT_HANDLER

#include <memory>

#include "Event/EventBase.h"

namespace Event {

  class Handler {
    public:
      virtual void handle (std::unique_ptr<EventBase>& event) = 0;

    protected:

  };

}

#endif //_H_EVENT_HANDLER
