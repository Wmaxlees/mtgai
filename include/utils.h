#pragma once

#ifndef _H_UTILS
#define _H_UTILS

#include <random>

template <typename T>
T randomVectorElement (std::vector<T>& collection) {
	std::random_device rd;
	std::mt19937 eng(rd());
	std::uniform_int_distribution<> distr(0, collection.size()-1);

	return collection[distr(eng)];
}

#endif //_H_UTILS
