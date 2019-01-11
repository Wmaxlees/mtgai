/**
 * @Author: W. Max Lees
 * @Date:   2018-12-21T12:19:12-07:00
 * @Email:  william.lees@nist.gov
 * @Last modified by:   W. Max Lees
 * @Last modified time: 2018-12-21T12:38:12-07:00
 */
#pragma once

#ifndef _H_EVENT_EPLAYCARD
#define _H_EVENT_EPLAYCARD

#include <memory>
#include <string>

#include "Card/CardInstance.h"
#include "Event/EventBase.h"

namespace mtg {
	namespace event {

		class PlayCardEvent : public EventBase {
		public:
			explicit PlayCardEvent(unsigned char playerIdx, std::shared_ptr<card::CardInstance> card);

			std::string getType() const override;

			unsigned char getPlayerIdx() const;
			std::shared_ptr<card::CardInstance> getCard() const;

		protected:
			unsigned char m_PlayerIdx;
			std::shared_ptr<card::CardInstance> m_Card;
		};

	}
}

#endif //_H_EVENT_EPLAYCARD
