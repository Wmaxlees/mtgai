
#include "Mana.h"

namespace mtg {

	Mana::Mana () {
		this->clear();
	}

	Mana::Mana(std::string manaString) {
		std::string delimiter = ";";

		size_t pos = 0;
		std::string token;

		int value = 0;

		value = Mana::getNextValue(manaString);
		this->m_Colorless = value;

		value = Mana::getNextValue(manaString);
		this->m_B = value;

		value = Mana::getNextValue(manaString);
		this->m_G = value;

		value = Mana::getNextValue(manaString);
		this->m_R = value;

		value = Mana::getNextValue(manaString);
		this->m_U = value;

		value = Mana::getNextValue(manaString);
		this->m_W = value;
	}


	Mana::~Mana () {
	}

	void Mana::clear () {
		this->m_B = 0;
		this->m_G = 0;
		this->m_R = 0;
		this->m_U = 0;
		this->m_W = 0;
		this->m_Colorless = 0;
	}

	bool Mana::contains (const ManaCost& cost) const {
		unsigned char colorless = 0;
		colorless += this->m_Colorless;

		if (this->m_B >= cost.m_B) {
			colorless += this->m_B - cost.m_B;
		} else {
			return false;
		}

		if (this->m_G >= cost.m_G) {
			colorless += this->m_G - cost.m_G;
		} else {
			return false;
		}

		if (this->m_R >= cost.m_R) {
			colorless += this->m_R - cost.m_R;
		} else {
			return false;
		}

		if (this->m_U >= cost.m_U) {
			colorless += this->m_U - cost.m_U;
		} else {
			return false;
		}

		if (this->m_W >= cost.m_W) {
			colorless += this->m_W - cost.m_W;
		} else {
			return false;
		}

		if (colorless >= cost.m_Colorless) {
			return true;
		}

		return false;
	}

	void Mana::add(const Mana &mana) {
		this->m_B += mana.m_B;
		this->m_G += mana.m_G;
		this->m_R += mana.m_R;
		this->m_U += mana.m_U;
		this->m_W += mana.m_W;
		this->m_Colorless += mana.m_Colorless;
	}

	unsigned char Mana::getColorless() const {
		return this->m_Colorless;
	}

	unsigned char Mana::getB() const {
		return this->m_B;
	}

	unsigned char Mana::getG() const {
		return this->m_G;
	}

	unsigned char Mana::getR() const {
		return this->m_R;
	}

	unsigned char Mana::getU() const {
		return this->m_U;
	}

	unsigned char Mana::getW() const {
		return this->m_W;
	}


	void Mana::remove(const ManaCost &cost) {
		unsigned char colorless = 0;
		colorless += this->m_Colorless;

		this->m_B -= cost.m_B;
		this->m_G -= cost.m_G;
		this->m_R -= cost.m_R;
		this->m_U -= cost.m_U;
		this->m_W -= cost.m_W;

		unsigned char colorless_deficit = cost.m_Colorless;

		if (colorless_deficit <= this->m_Colorless) {
			this->m_Colorless -= cost.m_Colorless;
			return;
		} else {
			colorless_deficit -= this->m_Colorless;
			this->m_Colorless = 0;
		}

		if (colorless_deficit <= this->m_B) {
			this->m_B -= colorless_deficit;
			return;
		} else {
			colorless_deficit -= this->m_B;
			this->m_B = 0;
		}

		if (colorless_deficit <= this->m_G) {
			this->m_G -= colorless_deficit;
			return;
		} else {
			colorless_deficit -= this->m_G;
			this->m_G = 0;
		}

		if (colorless_deficit <= this->m_R) {
			this->m_R -= colorless_deficit;
			return;
		} else {
			colorless_deficit -= this->m_R;
			this->m_R = 0;
		}

		if (colorless_deficit <= this->m_U) {
			this->m_U -= colorless_deficit;
			return;
		} else {
			colorless_deficit -= this->m_U;
			this->m_U = 0;
		}

		if (colorless_deficit <= this->m_W) {
			this->m_W -= colorless_deficit;
			return;
		} else {
			colorless_deficit -= this->m_W;
			this->m_W = 0;
		}

	}


	int Mana::getNextValue(std::string& manaCostString) {
		std::string delimiter = ";";

		size_t pos = 0;
		std::string token;

		pos = manaCostString.find(delimiter);
		token = manaCostString.substr(0, pos);
		int value = std::stoi(token);

		manaCostString.erase(0, pos + delimiter.length());

		return value;
	}

	std::ostream& operator<< (std::ostream& stream, const Mana& mana) {

		stream << "W: " << (unsigned int)mana.m_W <<
			" | U: " << (unsigned int)mana.m_U <<
			" | B: " << (unsigned int)mana.m_B <<
			" | R: " << (unsigned int)mana.m_R <<
			" | G: " << (unsigned int)mana.m_G <<
			" | " << (unsigned int)mana.m_Colorless;

		return stream;
	}

}
