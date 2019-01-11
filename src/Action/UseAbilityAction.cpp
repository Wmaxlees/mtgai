#include "Action/UseAbilityAction.h"

namespace mtg {
	namespace action {
		UseAbilityAction::UseAbilityAction() {}

		std::string UseAbilityAction::getType() const {
			return "UseAbility";
		}
	}
}