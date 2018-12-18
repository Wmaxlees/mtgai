#pragma once
#ifndef _H_VECTORIZE
#define _H_VECTORIZE

#include "Card.h"
#include "Game.h"

#include <vector>

namespace MTG {
	namespace vectorize {
		std::vector<float> card (CardInstance* card);
		std::vector<float> game (Game game);
	}
}

#endif //_H_VECTORIZE