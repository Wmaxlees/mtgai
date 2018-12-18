#pragma once

#ifndef _H_MANA
#define _H_MANA

#include "ManaCost.h"

class ManaCost;

namespace MTG {

	class Mana {
		public:
			Mana ();
			~Mana ();

			bool contains (const ManaCost &cost) const;
			void remove (const ManaCost &cost);

			void clear ();

		protected:
			unsigned char m_B;
			unsigned char m_G;
			unsigned char m_R;
			unsigned char m_U;
			unsigned char m_W;
			unsigned char m_Colorless;

	};
}

#endif
