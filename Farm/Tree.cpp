// Title: Tree.cpp
// Author: Tahmid Khan
// Date: 11/10/2025
// Description: Implementation of the Tree class (child of AgItem)

//Calls the tree class
#include "Tree.h"


//Tree constructor that sets the size to 0 and the worth to the base worth  
Tree::Tree() : AgItem(0, BASE_WORTH, false) {
  m_age = 0;
  m_fruit.clear();
}

//Destructor that deletes the fruit
Tree::~Tree(){
  for(unsigned int i = 0; i< m_fruit.size(); i++){
    delete m_fruit.at(i);
  }
  m_fruit.clear();
}

//Tick function that increases the age of the tree and checks if it is harvestable
void Tree::Tick(int &food) {
  m_age++;
  //Checks if the tree is harvestable
  if(m_age >= SEASONS_TO_HARVEST) {
    SetIsHarvestable(true);
    return;
  }
  //Checks if the tree is harvestable and if it is, it increases the size of the tree
  if(m_age % SEASONS_TO_SIZE == 0 && GetSize()< 3){
     SetSize(GetSize() + 1);
  }
  //Checks if the tree is harvestable and if it is, it increases the worth of the tree
  if(m_age >= SEASONS_TO_FRUIT) {
    Fruit* newFruit = new Fruit();
    m_fruit.push_back(newFruit);
    Harvest(food, food);
  }
}

//Harvest function that harvests the tree and increases the food and money
void Tree::Harvest(int &money, int &food) {
  //Checks if the tree is harvestable and if it is, it increases the money and food
  if(!m_fruit.empty()) {
    delete m_fruit.back();
    //Increases the money and food
    m_fruit.pop_back();
    food++;
  }
  //This means no money or food is gained
  if(GetIsHarvestable()) {
  }
}

//This function returns the type of the tree
string Tree::GetType() {
  return "Tree";
}

//This will print the tree informaton using the ostream operator
ostream &Tree::operator<<(ostream &os) {
  os << GetType() << CONCAT
     << TREE_SIZE[GetSize()] << CONCAT
     << (GetIsHarvestable() ? "Harvestable" : "Not Harvestable") << CONCAT
     << ((m_age >= SEASONS_TO_FRUIT && m_age < SEASONS_TO_HARVEST) ? "Fruiting" : "Not Fruiting") << CONCAT
     << "Fruit Count: " << m_fruit.size();
  return os;
}
