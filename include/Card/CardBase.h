#pragma once
#ifndef _H_CARD
#define _H_CARD

#include <memory>
#include <vector>

#include "Mana.h"
#include "ManaCost.h"
#include "Matrix.h"


namespace MTG {
  namespace Card {

  	class CardBase {
  		public:
  			static const unsigned char LAND = 1;
  			static const unsigned char CREATURE = 2;
  			static const unsigned char ARTIFACT = 4;
  			static const unsigned char ENCHANTMENT = 8;
  			static const unsigned char PLANESWALKER = 16;
  			static const unsigned char INSTANT = 32;
  			static const unsigned char SORCERY = 64;

        static const std::size_t VECTOR_SIZE = ManaCost::VECTOR_SIZE + 9;

  			static std::shared_ptr<CardBase> cardFromFile (std::string filename);
  			CardBase ();
  			~CardBase ();

  			bool isType (unsigned char type) const;

  			const ManaCost getCost () const;
  			std::string getName () const;
  			virtual bool isAffordable (const Mana& mana) const = 0;

  			void setName (std::string name);
  			void setCost (std::string manaCostString);
        virtual void setManaTap (std::string manaString) = 0;
  			virtual void setPower (unsigned char power) = 0;
  			virtual void setToughness (unsigned char toughness) = 0;

        virtual std::array<unsigned char, VECTOR_SIZE> vectorize () const = 0;

  			friend std::ostream& operator<< (std::ostream& stream, const CardBase& card);

  		protected:
  			unsigned char m_Type;
  			std::string m_Name;
  			ManaCost m_Cost;

  		private:


  	};

  	std::ostream& operator<< (std::ostream& stream, const CardBase& card);

  }
}


#endif //_H_CARD
