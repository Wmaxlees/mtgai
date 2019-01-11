#pragma once

#ifndef _H_ACTION_TAPLANDACTION
#define _H_ACTION_TAPLANDACTION

#include "Action/ActionBase.h"
#include "Card/CardInstance.h"
#include "Mana.h"

namespace mtg {
	namespace action {

		class TapLandAction : public ActionBase {
		public:
			explicit TapLandAction(unsigned char playerIdx, std::shared_ptr<card::CardInstance>card);

			std::string getType() const override;

		protected:
			const Mana m_Mana;
		};

	}
}

#endif //_H_ACTION_TAPLANDACTION