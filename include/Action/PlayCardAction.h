#pragma once

#ifndef _H_ACTION_PLAYCARDACTION
#define _H_ACTION_PLAYCARDACTION

#include <memory>
#include <string>

#include "Action/ActionBase.h"
#include "Card/CardInstance.h"

namespace mtg {
	namespace action {

		class PlayCardAction : public ActionBase {
		public:
			explicit PlayCardAction(unsigned char playerIdx, std::shared_ptr<card::CardInstance> card);

			std::string getType() const override;

		protected:
		};

	}
}

#endif //_H_ACTION_PLAYCARDACTION