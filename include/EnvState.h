/**
 * @Author: W. Max Lees
 * @Date:   2018-12-20T15:24:27-07:00
 * @Email:  william.lees@nist.gov
 * @Last modified by:   W. Max Lees
 * @Last modified time: 2018-12-21T15:37:27-07:00
 */

#pragma once

#ifndef _H_ENVSTATE
#define _H_ENVSTATE

#include <memory>

#include "Card/CardInstance.h"
#include "Matrix.h"

namespace mtg {

  class EnvState {
    public:
      EnvState(
        std::unique_ptr<Matrix<unsigned char, card::CardInstance::VECTOR_SIZE>> observation,
        int reward,
        bool done,
        std::shared_ptr<card::CardInstance> playCard
      );

      ~EnvState();

      bool isGameOver ();

    protected:
      std::unique_ptr<Matrix<unsigned char, card::CardInstance::VECTOR_SIZE>> m_Observation;
      int m_Reward;
      bool m_Done;
      std::shared_ptr<card::CardInstance> m_PlayCard;
  };

}

#endif //_H_ENVSTATE
