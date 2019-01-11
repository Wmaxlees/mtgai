#pragma once

#ifndef _H_EVENT_STARTDRAWSTEPEVENT
#define _H_EVENT_STARTDRAWSTEPEVENT

#include "Event/EventBase.h"

namespace mtg {
	namespace event {

		class StartDrawStepEvent : public EventBase {
		public:
			StartDrawStepEvent(unsigned char playerIdx);

			std::string getType() const override;
			unsigned char getPlayerIdx() const;


		protected:
			unsigned char m_PlayerIdx;
		};

	}
}

#endif //_H_EVENT_STARTDRAWSTEPEVENT
