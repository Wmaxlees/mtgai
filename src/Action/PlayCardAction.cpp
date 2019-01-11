#include "Action/PlayCardAction.h"

namespace mtg {
	namespace action {
		PlayCardAction::PlayCardAction(unsigned char playerIdx, std::shared_ptr<card::CardInstance> card) {
			this->m_Card = card;
			this->m_PlayerIdx = playerIdx;
		}

		std::string PlayCardAction::getType() const {
			return "PlayCardAction";
		}
	}
}