#pragma once

#ifndef _H_MANACOST
#define _H_MANACOST

#include <array>
#include <memory>
#include <string>

#include "Mana.h"

namespace MTG {

	class ManaCost
	{
		public:
      ManaCost ();
			ManaCost (std::string manaCostString);
			~ManaCost ();

      std::array<unsigned char, 7> vectorize () const;

			friend class Mana;

		protected:
			unsigned char m_B;
			unsigned char m_G;
			unsigned char m_R;
			unsigned char m_U;
			unsigned char m_W;
			unsigned char m_Colorless;
			unsigned char m_Xs;
	};

}

#endif //_H_MANACOST
