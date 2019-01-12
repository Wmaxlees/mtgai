#include "Event/DeclareAttackerEvent.h"

namespace mtg {
	namespace event {

		DeclareAttackerEvent::DeclareAttackerEvent(unsigned char playerIdx, unsigned char targetIdx, std::shared_ptr<card::CardInstance> card) {
			this->m_PlayerIdx = playerIdx;
			this->m_TargetIdx = targetIdx;
			this->m_Card = card;
		}

		std::string DeclareAttackerEvent::getType() const {
			return "DeclareAttacker";
		}

		unsigned char DeclareAttackerEvent::getPlayerIdx() const {
			return this->m_PlayerIdx;
		}

		unsigned char DeclareAttackerEvent::getTargetIdx() const {
			return this->m_PlayerIdx;
		}

		std::shared_ptr<card::CardInstance> DeclareAttackerEvent::getCard() const {
			return this->m_Card;
		}

	}
}

