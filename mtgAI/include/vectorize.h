#pragma once
#ifndef _H_VECTORIZE
#define _H_VECTORIZE

#include "Card.h"
#include "Game.h"

#include <vector>

namespace MTG {
	namespace vectorize {
		std::vector<float> card (const CardInstance* const card);
		std::vector<float> game (const Game* const game);
	}
}

#endif //_H_VECTORIZE
