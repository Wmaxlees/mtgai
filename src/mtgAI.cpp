// mtgAI.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <array>
#include <iostream>
#include <memory>
#include <ctime>

#include "Action/ActionBase.h"
#include "Card/CardManager.h"
#include "Game.h"
#include "Deck/DeckBase.h"
#include "Deck/DebugDeck.h"

int main(int argc, char** argv) {
	std::srand(unsigned(std::time(0)));

	std::cout << "Starting card manager..." << std::endl;
	mtg::card::CardManager cardManager;
	std::cout << "Loading land." << std::endl;
	std::shared_ptr<mtg::card::CardBase> land = cardManager.addCardFromFile("land.txt");
	std::cout << "Loading forest." << std::endl;
	std::shared_ptr<mtg::card::CardBase> forest = cardManager.addCardFromFile("forest.txt");
	std::cout << "Loading creature." << std::endl;
	std::shared_ptr<mtg::card::CardBase> mammoth = cardManager.addCardFromFile("creature.txt");

	std::cout << "Generating deck..." << std::endl;
	std::shared_ptr<mtg::deck::DebugDeck> deck = std::make_shared<mtg::deck::DebugDeck>();
	deck->addCard(land);
	deck->addCard(forest);
	deck->addCard(mammoth);

	std::array<std::shared_ptr<mtg::deck::DeckBase>, 6> decks;
	decks[0] = deck;
	decks[1] = deck;

	mtg::Game game(2, decks, true);



	for (std::size_t epoch = 0; epoch < 1000000; ++epoch) {
		game.reset();
		std::unique_ptr<mtg::EnvState> state = game.getCurrentState();
		while (!state->isGameOver()) {
			std::vector<std::shared_ptr<mtg::action::ActionBase>> moves = game.getCurrentMoveList();
			bool actionChosen = false;
			for (auto it = moves.begin(); it != moves.end(); ++it) {
				bool performAction = (bool)(rand() % 2);
				if (performAction) {
					actionChosen = true;
					game.perform(*it);
					break;
				}
			}

			if (!actionChosen) {
				// No move chosen, we're passing
				game.pass();
			}

			state = game.getCurrentState();
		}
	}
	//std::unique_ptr<Matrix<unsigned char, MTG::Card::Instance::VECTOR_SIZE>> result = game.reset();
  //std::cout << *result << std::endl;
}
