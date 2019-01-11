#include "Action/ActionBase.h"

namespace mtg {
	namespace action {
		const std::shared_ptr<card::CardInstance> ActionBase::getCard() const {
			return this->m_Card;
		}

		unsigned char ActionBase::getPlayerIdx() const {
			return this->m_PlayerIdx;
		}
	}
}