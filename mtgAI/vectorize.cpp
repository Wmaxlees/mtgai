#include "pch.h"
#include "vectorize.h"

namespace MTG {
	namespace vectorize {
		std::vector<float> card (CardInstance* card) {
			std::vector<float> result(20);

			if (card->isType(Card::ARTIFACT)) {
				result[0] = 1.0f;
			}

			if (card->isType(Card::CREATURE)) {
				result[1] = 1.0f;
			}

			if (card->isType(Card::ENCHANTMENT)) {
				result[2] = 1.0f;
			}

			if (card->isType(Card::INSTANT)) {
				result[3] = 1.0f;
			}

			if (card->isType(Card::LAND)) {
				result[4] = 1.0f;
			}

			if (card->isType(Card::PLANESWALKER)) {
				result[5] = 1.0f;
			}

			if (card->isType(Card::SORCERY)) {
				result[6] = 1.0f;
			}

			return result;
		}


		std::vector<float> game (Game game) {
			std::vector<float> result;



			return result;
		}
	}
}
