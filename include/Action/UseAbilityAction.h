#pragma once

#ifndef _H_ACTION_USEABILITYACTION
#define _H_ACTION_USEABILITYACTION

#include "Action/ActionBase.h"

namespace mtg {
	namespace action {
		
		class UseAbilityAction : public ActionBase {
		public:
			explicit UseAbilityAction();

			std::string getType() const override;
			
		protected:

		};

	}
}

#endif //_H_ACTION_USEABILITYACTION