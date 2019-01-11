#pragma once

#ifndef _H_MANA
#define _H_MANA

#include <iostream>

#include "ManaCost.h"

class ManaCost;

namespace mtg {

	class Mana {
	public:
		Mana();
		Mana(std::string manaString);

		~Mana();

		bool contains(const ManaCost &cost) const;
		void remove(const ManaCost &cost);

		void add(const Mana &mana);

		void clear();

		unsigned char getColorless() const;
		unsigned char getB() const;
		unsigned char getG() const;
		unsigned char getR() const;
		unsigned char getU() const;
		unsigned char getW() const;

		friend std::ostream& operator<< (std::ostream& stream, const Mana& mana);

	protected:
		unsigned char m_B;
		unsigned char m_G;
		unsigned char m_R;
		unsigned char m_U;
		unsigned char m_W;
		unsigned char m_Colorless;

		static int getNextValue(std::string& manaCostString);

	};

	std::ostream& operator<< (std::ostream& stream, const Mana& mana);
}

#endif
