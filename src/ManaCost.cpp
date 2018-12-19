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

  std::unique_ptr<unsigned char[]> ManaCost::vectorize () const {
    std::unique_ptr<unsigned char[]> result = std::make_unique<unsigned char[]>(7);
    result[0] = this->m_B;
    result[1] = this->m_G;
    result[2] = this->m_R;
    result[3] = this->m_U;
    result[4] = this->m_W;
    result[5] = this->m_Colorless;
    result[6] = this->m_Xs;

    return result;
  }
}
