#pragma once

#ifndef _H_ACTION_ACTIONBASE
#define _H_ACTION_ACTIONBASE

#include <string>

#include "Card/CardInstance.h"

namespace mtg {
	namespace action {

		class ActionBase {
		public:

			virtual std::string getType() const = 0;
			
			const std::shared_ptr<card::CardInstance> getCard() const;
			unsigned char getPlayerIdx() const;


		protected:
			std::shared_ptr<card::CardInstance> m_Card;
			unsigned char m_PlayerIdx;

		};

	}
}

#endif //_H_ACTION_ACTIONBASE
