#include <iostream>

#include "ManaCost.h"


namespace mtg {

	int getNextValue (std::string& manaCostString);

  ManaCost::ManaCost () : ManaCost("0;0;0;0;0;0;0") {
  }

	ManaCost::ManaCost (std::string manaCostString) {
		std::string delimiter = ";";

		size_t pos = 0;
		std::string token;

    int value = 0;

    value =  getNextValue(manaCostString);
		this->m_B = value;

    value =  getNextValue(manaCostString);
		this->m_G = value;

    value =  getNextValue(manaCostString);
		this->m_R = value;

    value =  getNextValue(manaCostString);
		this->m_U = value;

    value =  getNextValue(manaCostString);
		this->m_W = value;

    value =  getNextValue(manaCostString);
		this->m_Colorless = value;

    value =  getNextValue(manaCostString);
		this->m_Xs = value;


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

  std::array<unsigned char, 7> ManaCost::vectorize () const {
    std::array<unsigned char, 7> result{
      this->m_B,
      this->m_G,
      this->m_R,
      this->m_U,
      this->m_W,
      this->m_Colorless,
      this->m_Xs
    };

    return result;
  }
}
