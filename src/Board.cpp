#include <iostream>

#include "Action/DeclareAttackerAction.h"
#include "Action/TapLandAction.h"
#include "Board.h"
#include "Card/Land.h"

namespace mtg {

	Board::Board() {
	}


	Board::~Board() {
	}


	void Board::addCard(std::shared_ptr<card::CardInstance> card) {
		this->m_Cards.push_back(card);
	}

	void Board::untapAll() {
		for (std::shared_ptr<card::CardInstance> card : this->m_Cards) {
			if (card->isTapped()) {
				card->untap();
			}
		}
	}


	std::vector<std::shared_ptr<const card::CardInstance>> Board::getCardsOfType(unsigned int type, bool onlyUntapped) const {
		std::vector<std::shared_ptr<const card::CardInstance>> result;

		for (std::shared_ptr<const card::CardInstance> card : this->m_Cards) {
			if (card->isType(type)) {
				if (onlyUntapped && card->isTapped()) {
					continue;
				}

				result.push_back(card);
			}
		}

		return result;
	}


	std::vector<std::shared_ptr<const card::CardInstance>> Board::getCardsOfType(unsigned int type) const {
		return this->getCardsOfType(type, false);
	}


	std::unique_ptr<Matrix<unsigned char, card::CardInstance::VECTOR_SIZE>> Board::vectorize(unsigned char playerIdx) const {
		std::unique_ptr<Matrix<unsigned char, card::CardInstance::VECTOR_SIZE>> result = std::make_unique<Matrix<unsigned char, card::CardInstance::VECTOR_SIZE>>();

		for (std::shared_ptr<const card::CardInstance> card : this->m_Cards) {
			std::array<unsigned char, card::CardInstance::VECTOR_SIZE> cardVector = card->vectorize(true, playerIdx);
			result->put(cardVector);
		}

		return result;
	}

	const std::vector<std::shared_ptr<action::ActionBase>> Board::getPlayableAbilities(unsigned char playerIdx, const Mana mana) const {
		const std::vector<std::shared_ptr<action::ActionBase>> result;

		return result;
	}

	const std::vector<std::shared_ptr<action::ActionBase>> Board::getTappableLands(unsigned char playerIdx) const {
		std::vector<std::shared_ptr<action::ActionBase>> result;
		for (auto it = this->m_Cards.begin(); it != this->m_Cards.end(); ++it) {
			if (!(*it)->isTapped() && (*it)->isType(card::CardBase::LAND)) {
				result.push_back(std::make_shared<action::TapLandAction>(playerIdx, *it));
			}
		}

		return result;
	}

	const std::vector<std::shared_ptr<action::ActionBase>> Board::getDeclareAttackerMoves(unsigned char playerIdx, unsigned char targetIdx) const {
		std::vector<std::shared_ptr<action::ActionBase>> result;

		for (auto it = this->m_Cards.begin(); it != this->m_Cards.end(); ++it) {
			if (!(*it)->isTapped() && !(*it)->hasSummoningSickness() && (*it)->isType(card::CardBase::CREATURE)) {
				result.push_back(std::make_shared<action::DeclareAttackerAction>(playerIdx, targetIdx, *it));
			}
		}

		return result;
	}


	void Board::removeAllSummoningSickness() {
		for (const std::shared_ptr<card::CardInstance>& card : this->m_Cards) {
			card->resetSummoningSickness();
		}
	}


	std::ostream& operator<< (std::ostream& stream, const Board& board) {
		for (const std::shared_ptr<card::CardInstance>& card : board.m_Cards) {
			stream << *card;
		}

		return stream;
	}

}
