// mtgAI.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"

#include "CardManager.h"
#include "Game.h"
#include "Library.h"
#include "DebugLibrary.h"

#include <vector>

int main (int argc, char** argv) {
	MTG::CardManager cardManager;
	MTG::Card* land = cardManager.addCardFromFile("land.txt");
	MTG::Card* forest = cardManager.addCardFromFile("forest.txt");
	MTG::Card* mammoth = cardManager.addCardFromFile("creature.txt");

	MTG::DebugLibrary* deckA = new MTG::DebugLibrary();
	MTG::DebugLibrary* deckB = new MTG::DebugLibrary();

	deckA->addCard(land);
	deckA->addCard(forest);
	deckA->addCard(mammoth);

	deckB->addCard(land);
	deckB->addCard(forest);
	deckB->addCard(mammoth);

	std::vector<MTG::Library*> decks(2);
	decks[0] = deckA;
	decks[1] = deckB;

	MTG::Game game(2, decks, true);

	game.initialize();
}

