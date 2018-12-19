#include "pch.h"
#include "StandardLibrary.h"

#include <algorithm>

namespace MTG {

	StandardLibrary::StandardLibrary () {
		this->m_Cards = std::deque<CardInstance*>(60);
	}


	StandardLibrary::~StandardLibrary () {
		if (!this->m_Cards.empty()) {
			for (std::deque<CardInstance*>::iterator it = this->m_Cards.begin(); it != this->m_Cards.end(); ++it) {
				delete (*it);
			}

			this->m_Cards.clear();
		}
	}


	bool StandardLibrary::empty() const {
		return this->m_Cards.empty();
	}


	void StandardLibrary::shuffle () {
		std::random_shuffle(this->m_Cards.begin(), this->m_Cards.end());
	}


	CardInstance* StandardLibrary::getNextCard () {
		if (this->m_Cards.empty()) {
			return nullptr;
		}

		CardInstance* result = this->m_Cards.front();
		this->m_Cards.pop_front();

		return result;
	}

}
