// Title: Vegetable.cpp
// Author: Tahmid Khan
// Date: 11/10/2025
// Description: Implementation of the Vegetable class (child of AgItem)

//Calls the Vegetable class
#include "Vegetable.h"

//Initializes the Vegetable class
Vegetable::Vegetable() : AgItem(0, BASE_WORTH, false) {
}

//This function will tick the vegetable and increase its size
void Vegetable::Tick(int &food) {
  //Increases the size of the vegetable
  if(GetSize() < MAX_VEG_SIZE) {
    SetSize(GetSize() + 1);
    //If the vegetable is at max size, it will be harvestable
    if(GetSize() == MAX_VEG_SIZE) {
      SetIsHarvestable(true);
    }
  }
}

//This function will harvest the vegetable and increase the food
void Vegetable::Harvest(int &money, int &food) {
  //If the vegetable is harvestable, it will be harvested and the food will be increased
  if(GetIsHarvestable()){
    food += GetSize();
    SetSize(0);
    SetIsHarvestable(false);
  }
}

//This function will return the type of the vegetable
string Vegetable::GetType() {
  return "Vegetable";
}

//This prints the vegetable to the console
ostream &Vegetable::operator<<(ostream &os) {
  os << GetType() << CONCAT
     << (GetIsHarvestable() ? "Harvestable" : "Not Harvestable") << CONCAT
     << Veg_Size[GetSize()];
  return os;
}
