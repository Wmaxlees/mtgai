#include "pch.h"
#include "ManaCost.h"


namespace MTG {

	int getNextValue (std::string& manaCostString);

	ManaCost::ManaCost (std::string manaCostString) {
		std::string delimiter = ";";

		size_t pos = 0;
		std::string token;

		this->m_B = getNextValue(manaCostString);
		this->m_G = getNextValue(manaCostString);
		this->m_R = getNextValue(manaCostString);
		this->m_U = getNextValue(manaCostString);
		this->m_W = getNextValue(manaCostString);
		this->m_Colorless = getNextValue(manaCostString);
		this->m_Xs = getNextValue(manaCostString);
	}


	ManaCost::~ManaCost () {
	}

	int getNextValue (std::string& manaCostString) {
		std::string delimiter = ";";

		size_t pos = 0;
		std::string token;

		pos = manaCostString.find(delimiter);
		token = manaCostString.substr(0, pos);
		int value = std::stoi(token);

		manaCostString.erase(0, pos + delimiter.length());

		return value;
	}
}
