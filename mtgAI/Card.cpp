#include "pch.h"
#include "Card.h"
#include "CardCreature.h"
#include "CardLand.h"

#include <string>
#include <fstream>

namespace MTG {
	Card* Card::cardFromFile(std::string filename) {
		Card* result = nullptr;

		std::ifstream cardFile(filename.c_str());

		std::string line;

		// Check the type
		std::getline(cardFile, line);
		int intValue = std::stoi(line);
		switch (intValue) {
			case Card::ARTIFACT:
				
				break;
			case Card::CREATURE:
				result = new CardCreature();

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
			case Card::ENCHANTMENT:

				break;
			case Card::INSTANT:

				break;
			case Card::LAND:
				result = new CardLand();

				std::getline(cardFile, line);
				result->setName(line);

				break;
			case Card::PLANESWALKER:

				break;
			case Card::SORCERY:

				break;
			default:

				break;
		}

		return result;
	}

	Card::Card () {

	}

	Card::~Card () {
		delete this->m_Cost;
		this->m_Cost = nullptr;
	}


	bool Card::isType (unsigned char type) const {
		return (this->m_Type & type) == type;
	}

	std::string Card::getName () const {
		return this->m_Name;
	}

	void Card::setCost (std::string manaCostString) {
		this->m_Cost = new ManaCost(manaCostString);
	}

	void Card::setName (std::string name) {
		this->m_Name = name;
	}

	const ManaCost* const Card::getCost() const {
		return this->m_Cost;
	}

	std::ostream& operator<< (std::ostream& stream, const Card& card) {
		stream << "[" << card.getName() << "]";

		return stream;
	}
}
