// mtgAI.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <array>
#include <iostream>
#include <memory>
#include <ctime>

#include "Card/Manager.h"
#include "Game.h"
#include "Deck/DeckBase.h"
#include "Deck/DebugDeck.h"

int main (int argc, char** argv) {
  std::srand ( unsigned ( std::time(0) ) );

  std::cout << "Starting card manager..." << std::endl;
	MTG::Card::Manager cardManager;
  std::cout << "Loading land." << std::endl;
	std::shared_ptr<MTG::Card::CardBase> land = cardManager.addCardFromFile("land.txt");
  std::cout << "Loading forest." << std::endl;
	std::shared_ptr<MTG::Card::CardBase> forest = cardManager.addCardFromFile("forest.txt");
  std::cout << "Loading creature." << std::endl;
	std::shared_ptr<MTG::Card::CardBase> mammoth = cardManager.addCardFromFile("creature.txt");

  std::cout << "Generating deck..." << std::endl;
	std::shared_ptr<MTG::Deck::DebugDeck> deck = std::make_shared<MTG::Deck::DebugDeck>();
	deck->addCard(land);
	deck->addCard(forest);
	deck->addCard(mammoth);

  std::array<std::shared_ptr<MTG::Deck::DeckBase>, 6> decks;
	decks[0] = deck;
	decks[1] = deck;

	MTG::Game game(2, decks, true);

  game.reset();
	//std::unique_ptr<Matrix<unsigned char, MTG::Card::Instance::VECTOR_SIZE>> result = game.reset();
  //std::cout << *result << std::endl;
}
