/**
 * @Author: W. Max Lees
 * @Date:   2018-12-20T15:24:27-07:00
 * @Email:  william.lees@nist.gov
 * @Last modified by:   W. Max Lees
 * @Last modified time: 2018-12-21T12:12:15-07:00
 */

#pragma once

#ifndef _H_ENVSTATE
#define _H_ENVSTATE

#include <memory>

#include "Card/Instance.h"
#include "Matrix.h"

namespace MTG {

  class EnvState {
    public:
      EnvState(
        std::unique_ptr<Matrix<unsigned char, Card::Instance::VECTOR_SIZE>> observation,
        int reward,
        bool done,
        std::shared_ptr<Card::Instance> playCard
      );

      ~EnvState();

    protected:
      std::unique_ptr<Matrix<unsigned char, Card::Instance::VECTOR_SIZE>> m_Observation;
      int m_Reward;
      bool m_Done;
      std::shared_ptr<Card::Instance> m_PlayCard;
  };

}

#endif //_H_ENVSTATE
