#pragma once

#ifndef _H_EVENT_DECLAREATTACKEREVENT
#define _H_EVENT_DECLAREATTACKEREVENT

#include "Card/CardInstance.h"
#include "Event/EventBase.h"

namespace mtg {
	namespace event {

		class DeclareAttackerEvent : public EventBase {
		public:
			explicit DeclareAttackerEvent(unsigned char playerIdx, unsigned char targetIdx, std::shared_ptr<card::CardInstance> card);

			std::string getType() const override;

			unsigned char getPlayerIdx() const;
			unsigned char getTargetIdx() const;
			std::shared_ptr<card::CardInstance> getCard() const;

		protected:
			unsigned char m_PlayerIdx;
			unsigned char m_TargetIdx;
			std::shared_ptr<card::CardInstance> m_Card;

		};

	}
}


#endif //_H_EVENT_DECLAREATTACKEREVENT