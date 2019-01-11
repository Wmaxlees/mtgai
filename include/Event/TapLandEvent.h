#pragma once

#ifndef _H_EVENT_TAPLANDEVENT
#define _H_EVENT_TAPLANDEVENT

#include "Card/CardInstance.h"
#include "Event/EventBase.h"


namespace mtg {
	namespace event {

		class TapLandEvent : public EventBase {
		public:
			TapLandEvent(unsigned char playerIdx, std::shared_ptr<card::CardInstance> card);

			std::string getType() const override;
			std::shared_ptr<card::CardInstance> getCard() const;

		private:
			unsigned char m_PlayerIdx;
			std::shared_ptr<card::CardInstance> m_Card;

		};

	}
}


#endif //_H_EVENT_TAPLANDEVENT