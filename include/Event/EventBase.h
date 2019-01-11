/**
 * @Author: W. Max Lees
 * @Date:   2018-12-21T11:12:34-07:00
 * @Email:  william.lees@nist.gov
 * @Last modified by:   W. Max Lees
 * @Last modified time: 2018-12-21T14:33:59-07:00
 */

#pragma once

#ifndef _H_EVENT_EVENTBASE
#define _H_EVENT_EVENTBASE

#include <string>

namespace mtg {
	namespace event {

		class EventBase {
			public:
				virtual std::string getType() const = 0;

			protected:


		};
	}
}

#endif //_H_EVENT_EVENTBASE
