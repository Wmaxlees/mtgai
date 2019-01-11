/**
 * @Author: W. Max Lees
 * @Date:   2018-12-21T12:47:28-07:00
 * @Email:  william.lees@nist.gov
 * @Last modified by:   W. Max Lees
 * @Last modified time: 2018-12-21T12:57:09-07:00
 */
#include "Event/GameStartEvent.h"

namespace mtg {
	namespace event {
		GameStartEvent::GameStartEvent() {
		}

		std::string GameStartEvent::getType() const {
			return "GameStart";
		}
	}
}
