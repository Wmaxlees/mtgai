#include "Card/Land.h"


namespace MTG {
  namespace Card {
    int getNextValue (std::string& manaCostString);

  	Land::Land () {
  	}


  	Land::~Land () {
  	}

    void Land::setManaTap (std::string manaString) {
      std::string delimiter = ";";

  		size_t pos = 0;
  		std::string token;

      int value = 0;

      value =  getNextValue(manaString);
  		this->m_LandColorless = value;

      value =  getNextValue(manaString);
  		this->m_LandB = value;

      value =  getNextValue(manaString);
  		this->m_LandG = value;

      value =  getNextValue(manaString);
  		this->m_LandR = value;

      value =  getNextValue(manaString);
  		this->m_LandU = value;

      value =  getNextValue(manaString);
  		this->m_LandW = value;
    }

  	void Land::setPower (unsigned char power) {
  	}

  	void Land::setToughness (unsigned char toughness) {
  	}

  	bool Land::isAffordable(const Mana& mana) const {
  		return true;
  	}

    std::array<unsigned char, CardBase::VECTOR_SIZE> Land::vectorize () const {
      // 0 type
      // 1-7 for mana cost
      // 8-13 mana provided by tapping
      // 14 power
      // 15 toughness
      std::array<unsigned char, CardBase::VECTOR_SIZE> result;
      result[0] = CardBase::LAND;

      for (std::size_t idx = 1; idx < 8; ++idx) {
        result[idx] = 0;
      }

      result[8] = this->m_LandColorless;
      result[9] = this->m_LandB;
      result[10] = this->m_LandG;
      result[11] = this->m_LandR;
      result[12] = this->m_LandU;
      result[13] = this->m_LandW;

      result[14] = 0;
      result[15] = 0;

      return result;
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
}
