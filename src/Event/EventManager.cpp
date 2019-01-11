/**
 * @Author: W. Max Lees
 * @Date:   2018-12-21T11:28:25-07:00
 * @Email:  william.lees@nist.gov
 * @Last modified by:   W. Max Lees
 * @Last modified time: 2018-12-21T16:12:32-07:00
 */
#include <algorithm>
#include <iostream>

#include "Event/EventManager.h"

namespace mtg {
	namespace event {

		void EventManager::reg(std::string eventName, EventHandler* handler) {
			// TODO: Check for duplicates
			this->m_Handlers[eventName].push_back(handler);
		}

		void EventManager::unreg(std::string eventName, EventHandler* handler) {
			this->m_Handlers[eventName].erase(std::remove(this->m_Handlers[eventName].begin(), this->m_Handlers[eventName].end(), handler), this->m_Handlers[eventName].end());
		}

		void EventManager::trigger(std::unique_ptr<EventBase> event) const {
			std::string eventName = event->getType();

			if (this->m_Handlers.count(eventName) == 0) {
				return;
			}

			for (auto it = this->m_Handlers.at(eventName).cbegin(); it != this->m_Handlers.at(eventName).cend(); ++it) {
				(*it)->handle(event);
			}
		}

	}
}
