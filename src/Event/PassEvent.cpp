/**
 * @Author: W. Max Lees
 * @Date:   2018-12-21T12:47:28-07:00
 * @Email:  william.lees@nist.gov
 * @Last modified by:   W. Max Lees
 * @Last modified time: 2018-12-21T14:31:22-07:00
 */
 #include "Event/PassEvent.h"

namespace mtg {
	namespace event {
		PassEvent::PassEvent() {}

		std::string PassEvent::getType() const {
			return "Pass";
		}
	}
}
