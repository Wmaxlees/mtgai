/**
 * @Author: W. Max Lees
 * @Date:   2018-12-21T12:47:28-07:00
 * @Email:  william.lees@nist.gov
 * @Last modified by:   W. Max Lees
 * @Last modified time: 2018-12-21T13:40:22-07:00
 */
 #include "Event/ENewStep.h"

 namespace Event {
   ENewStep::ENewStep (unsigned char playerID, unsigned char stepID) {
     this->m_PlayerID = playerID;
     this->m_StepID = stepID;
   }

   std::string ENewStep::getType () const {
     return "NewStep";
   }

   unsigned char ENewStep::getPlayerID () const {
     return this->m_PlayerID;
   }
 }
