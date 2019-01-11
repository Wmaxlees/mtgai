#include "Event/TapLandEvent.h"

namespace mtg {
	namespace event {

		TapLandEvent::TapLandEvent(unsigned char playerIdx, std::shared_ptr<card::CardInstance> card) {
			this->m_PlayerIdx = playerIdx;
			this->m_Card = card;
		}

		std::string TapLandEvent::getType() const {
			return "TapLand";
		}

		std::shared_ptr<card::CardInstance> TapLandEvent::getCard() const {
			return this->m_Card;
		}

	}
}