/**
 * @Author: W. Max Lees
 * @Date:   2018-12-21T12:09:44-07:00
 * @Email:  william.lees@nist.gov
 * @Last modified by:   W. Max Lees
 * @Last modified time: 2018-12-21T12:12:07-07:00
 */

#include "EnvState.h"

namespace MTG {

  EnvState::EnvState(
    std::unique_ptr<Matrix<unsigned char, Card::Instance::VECTOR_SIZE>> observation,
    int reward,
    bool done,
    std::shared_ptr<Card::Instance> playCard
  ) {
    this->m_Observation = move(observation);
    this->m_Reward = reward;
    this->m_Done = done;
    this->m_PlayCard = playCard;
  }

  EnvState::~EnvState () {
  }

}
