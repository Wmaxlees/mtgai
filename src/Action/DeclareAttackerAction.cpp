#include "Action/DeclareAttackerAction.h"

namespace mtg {
	namespace action {
		DeclareAttackerAction::DeclareAttackerAction(unsigned char playerIdx, unsigned char targetIdx, std::shared_ptr<card::CardInstance> card) {
			this->m_Card = card;
			this->m_PlayerIdx = playerIdx;
			this->m_TargetIdx = targetIdx;
		}

		unsigned char DeclareAttackerAction::getTargetIdx() const {
			return this->m_TargetIdx;
		}

		std::string DeclareAttackerAction::getType() const {
			return "DeclareAttackerAction";
		}
	}
}