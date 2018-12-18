#include "pch.h"
#include "Mana.h"

namespace MTG {

	Mana::Mana () {
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

}
