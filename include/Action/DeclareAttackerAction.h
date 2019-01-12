#pragma once

#ifndef _H_ACTION_ATTACKACTION
#define _H_ACTION_ATTACKACTION

#include "Action/ActionBase.h"

namespace mtg {
	namespace action {

		class DeclareAttackerAction : public ActionBase {
		public:
			explicit DeclareAttackerAction(unsigned char playerIdx, unsigned char targetIdx, std::shared_ptr<card::CardInstance> card);

			unsigned char getTargetIdx() const;

			std::string getType() const override;

		protected:
			unsigned char m_TargetIdx;
		};

	}
}


#endif //_H_ACTION_ATTACKACTION