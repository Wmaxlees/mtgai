/**
 * @Author: W. Max Lees
 * @Date:   2018-12-21T12:18:59-07:00
 * @Email:  william.lees@nist.gov
 * @Last modified by:   W. Max Lees
 * @Last modified time: 2018-12-21T12:34:11-07:00
 */
#include "Event/PlayCardEvent.h"

namespace mtg {
	namespace event {
		PlayCardEvent::PlayCardEvent (unsigned char playerIdx, std::shared_ptr<card::CardInstance> card) {
			this->m_PlayerIdx = playerIdx;
			this->m_Card = card;
		}


		unsigned char PlayCardEvent::getPlayerIdx() const {
			return this->m_PlayerIdx;
		}


		std::shared_ptr<card::CardInstance> PlayCardEvent::getCard() const {
			return this->m_Card;
		}


		std::string PlayCardEvent::getType() const {
			return "PlayCard";
		}
	}
}
