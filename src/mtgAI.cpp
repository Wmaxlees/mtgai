// mtgAI.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"

#include "CardManager.h"
#include "Game.h"
#include "Library.h"
#include "DebugLibrary.h"

#include <iostream>
#include <memory>

int main (int argc, char** argv) {
  std::cout << "Starting card manager..." << std::endl;
	MTG::CardManager cardManager;
	std::shared_ptr<MTG::Card> land = cardManager.addCardFromFile("land.txt");
	std::shared_ptr<MTG::Card> forest = cardManager.addCardFromFile("forest.txt");
	std::shared_ptr<MTG::Card> mammoth = cardManager.addCardFromFile("creature.txt");

  std::cout << "Generating decks..." << std::endl;
	MTG::DebugLibrary* deckA = new MTG::DebugLibrary();
	MTG::DebugLibrary* deckB = new MTG::DebugLibrary();

	deckA->addCard(land);
	deckA->addCard(forest);
	deckA->addCard(mammoth);

	deckB->addCard(land);
	deckB->addCard(forest);
	deckB->addCard(mammoth);

  MTG::Library* decks[2];
	decks[0] = deckA;
	decks[1] = deckB;

	MTG::Game game(2, decks, true);

	game.reset();
}
