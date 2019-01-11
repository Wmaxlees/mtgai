#include "Event/StartDrawStepEvent.h"

namespace mtg {
	namespace event {
		StartDrawStepEvent::StartDrawStepEvent(unsigned char playerIdx) {
			this->m_PlayerIdx = playerIdx;
		}


		std::string StartDrawStepEvent::getType() const {
			return "StartDrawStep";
		}


		unsigned char StartDrawStepEvent::getPlayerIdx() const {
			return this->m_PlayerIdx;
		}
	}
}