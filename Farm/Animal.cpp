// Title: Animal.cpp
// Author: Tahmid Khan
// Date: 11/08/2025
// Description: Implementation of the Animal class (child of AgItem)

//Includes the Animal class header file
#include "Animal.h"


//Default constructor that sets the name and hunger status
Animal::Animal() : AgItem(0, BASE_WORTH, false) {
  m_name = "Chicken";     
  m_IsHungry = false;     
}
  
// The animal may grow or be harvested if unfed twice
void Animal::Tick(int &food) {
  if (food > 0) {
    // If there is food available then it will feed the animal
    food--;             
    if (!GetIsHarvestable()) {
      SetSize(GetSize() + 1); 
      if (GetSize() >= ANIMAL_MAX_SIZE) {
        SetIsHarvestable(true); 
      }
    }
    m_IsHungry = false; 
  } else {
    //No food available this season
    if (m_IsHungry) {
      //if it was hungry last season too then harvest 
      SetIsHarvestable(true);
    } else {
      m_IsHungry = true;
    }
  }
}


// If the animal is harvestable then it will gain money and reset growth
void Animal::Harvest(int &money, int &food) {
  if (GetIsHarvestable()) {
    money += (GetWorth() * GetSize()); 
    SetSize(0);                         
    SetIsHarvestable(false);           
    m_IsHungry = false;                 
  }
}

// Returns the string name of this subtype
string Animal::GetType() {
  return "Animal";
}

// Prints the animal's details, the ostream allows for easy printing to file
ostream &Animal::operator<<(ostream &os) {
  os << GetType() << CONCAT
     << m_name << CONCAT
     << (GetIsHarvestable() ? "Harvestable" : "Not Harvestable") << CONCAT
     << ANIMAL_SIZE[GetSize()] << CONCAT
     << (m_IsHungry ? "Hungry" : "Fed");
  return os;
}
