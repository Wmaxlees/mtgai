#include <string>
#include <fstream>

#include "Card/CardBase.h"
#include "Card/Creature.h"
#include "Card/Land.h"

namespace MTG {
  namespace Card {
  	std::shared_ptr<CardBase> CardBase::cardFromFile(std::string filename) {
  		std::shared_ptr<CardBase> result;

  		std::ifstream cardFile(filename.c_str());

  		std::string line;

  		// Check the type
  		std::getline(cardFile, line);
  		int intValue = std::stoi(line);
  		switch (intValue) {
  			case CardBase::ARTIFACT:

  				break;
  			case CardBase::CREATURE:
  				result = std::make_shared<Card::Creature>();

  				std::getline(cardFile, line);
  				result->setName(line);

  				std::getline(cardFile, line);
  				result->setCost(line);

  				std::getline(cardFile, line);
  				intValue = std::stoi(line);
  				result->setPower(intValue);

  				std::getline(cardFile, line);
  				intValue = std::stoi(line);
  				result->setToughness(intValue);

  				break;
  			case CardBase::ENCHANTMENT:

  				break;
  			case CardBase::INSTANT:

  				break;
  			case CardBase::LAND:
  				result = std::make_shared<Card::Land>();

  				std::getline(cardFile, line);
  				result->setName(line);

  				break;
  			case CardBase::PLANESWALKER:

  				break;
  			case CardBase::SORCERY:

  				break;
  			default:

  				break;
  		}

  		return result;
  	}

  	CardBase::CardBase () {

  	}

  	CardBase::~CardBase () {
  	}


  	bool CardBase::isType (unsigned char type) const {
  		return (this->m_Type & type) == type;
  	}

  	std::string CardBase::getName () const {
  		return this->m_Name;
  	}

  	void CardBase::setCost (std::string manaCostString) {
  		this->m_Cost = ManaCost(manaCostString);
  	}

  	void CardBase::setName (std::string name) {
  		this->m_Name = name;
  	}

  	const ManaCost CardBase::getCost() const {
  		return this->m_Cost;
  	}

  	std::ostream& operator<< (std::ostream& stream, const CardBase& card) {
  		stream << "[" << card.getName() << "]";

  		return stream;
  	}
  }
}
