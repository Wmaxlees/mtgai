/**
 * @Author: W. Max Lees
 * @Date:   2018-12-21T11:20:29-07:00
 * @Email:  william.lees@nist.gov
 * @Last modified by:   W. Max Lees
 * @Last modified time: 2018-12-21T16:12:40-07:00
 */
#pragma once

#ifndef _H_EVENT_MANAGER
#define _H_EVENT_MANAGER

#include <map>
#include <memory>
#include <string>
#include <vector>

#include "Event/EventBase.h"
#include "Event/EventHandler.h"

namespace mtg {
	namespace event {
		class EventManager {
			public:
				void trigger (std::unique_ptr<EventBase> event) const;
				void reg (std::string eventName, EventHandler* handler);
				void unreg (std::string eventName, EventHandler* handler);

			protected:
				std::map<std::string, std::vector<EventHandler*>> m_Handlers;
		};
	}
}

#endif //_H_EVENT_MANAGER
