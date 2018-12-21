/**
 * @Author: W. Max Lees
 * @Date:   2018-12-21T12:47:28-07:00
 * @Email:  william.lees@nist.gov
 * @Last modified by:   W. Max Lees
 * @Last modified time: 2018-12-21T14:51:38-07:00
 */
 #include "Event/ENewPhase.h"

 namespace Event {
   ENewPhase::ENewPhase (unsigned char playerID, unsigned char phaseID) {
     this->m_PlayerID = playerID;
     this->m_PhaseID = phaseID;
   }

   std::string ENewPhase::getType () const {
     return "NewPhase";
   }

   unsigned char ENewPhase::getPlayerID () const {
     return this->m_PlayerID;
   }

   unsigned char ENewPhase::getPhaseID () const {
     return this->m_PhaseID;
   }
 }
