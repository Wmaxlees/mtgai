/**
 * @Author: W. Max Lees
 * @Date:   2018-12-21T14:28:32-07:00
 * @Email:  william.lees@nist.gov
 * @Last modified by:   W. Max Lees
 * @Last modified time: 2018-12-21T14:34:35-07:00
 */
 #pragma once

 #ifndef _H_EVENT_EPASS
 #define _H_EVENT_EPASS


 #include "Event/EventBase.h"

 namespace Event {

   class EPass : public EventBase {
     public:
       EPass ();
       std::string getType () const override;

     protected:
   };

 }

 #endif //_H_EVENT_PASS
