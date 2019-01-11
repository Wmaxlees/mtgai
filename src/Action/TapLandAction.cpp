#include "Action/TapLandAction.h"

namespace mtg {
	namespace action {
		TapLandAction::TapLandAction(unsigned char playerIdx, std::shared_ptr<card::CardInstance>card) {
			this->m_PlayerIdx = playerIdx;
			this->m_Card = card;
		}

		std::string TapLandAction::getType() const {
			return "TapLandAction";
		}
	}
}