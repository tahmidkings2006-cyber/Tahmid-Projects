// Title: Farm.cpp
// Author: Tahmid Khan
// Date: 11/10/2025
// Description: Implementation of the Farm class (manages all agricultural items and game simulation)

//Includes the farm class and all the agricultural items
#include "Farm.h"

//Constructor for the farm class, it declares the food and money and sets the season to 1 because the game starts at season 1
Farm::Farm() {
  m_food = 6;
  m_money = 0;
  m_season = 1;
}

//Destructor for the farm class, it deletes all the agricultural items and clears the vector
Farm::~Farm() {
  for (unsigned int i = 0; i < m_farm.size(); i++) {
    delete m_farm.at(i);
  }
  m_farm.clear();
}

//Menu function for the farm class, it displays the menu and returns the choice of the user
int Farm::Menu() {
  int choice = 0;
  cout << "What would you like to do?" << endl;
  cout << "1. Add Item to Farm" << endl;
  cout << "2. Add Two of Each Item to Farm" << endl;
  cout << "3. Simulate Time" << endl;
  cout << "4. Farm Status" << endl;
  cout << "5. Quit" << endl;
  cin >> choice;
  while(choice < 1|| choice > 5) {
    cout << "Invalid choice. Please try again." << endl;
    cin >> choice;
  }
  return choice;
}

//ChooseItem function for the farm class, it displays the menu and returns the choice of the user
int Farm::ChooseItem() {
  int type = 0;
  cout << "What type of item would you like to add?" << endl;
  cout << "1. Animal" << endl;
  cout << "2. Vegetable" << endl;
  cout << "3. Tree" << endl;
  cin >> type;
  while(type < 1 || type > 3) {
    cout << "Invalid choice. Please try again." << endl;
    cin >> type;
  }
  return type;
}

//AddItem function for the farm class, it adds the item to the farm and displays the message
void Farm::AddItem(int type, int quantity) {
  //if the type is 1, it adds an animal to the farm
  for(int i = 0; i < quantity; i++) {
    AgItem* newItem = nullptr;
    if(type == 1) {
      newItem = new Animal();
    } else if(type == 2) {
      newItem = new Vegetable();
    } else if(type == 3) {
      newItem = new Tree();
    }
    //if the item is not null, it adds it to the farm
    m_farm.push_back(newItem);
  }
   cout << quantity << " item(s) added to the farm." << endl;
}

//Tick function for the farm class, it ticks the farm for the number of seasons and displays the message
void Farm::Tick(int numSeasons) {
  //if the number of seasons is less than 1, it displays the message
  for(int i = 0; i < numSeasons; i++) {
    cout << "SEASON: " << m_season << endl;
    cout << "************" << endl;
    unsigned int j = 0; 
    //if the farm is not empty, it ticks all the items in the farm
    while(j < m_farm.size()) {
      m_farm.at(j)->Tick(m_food);
      //if the item is harvestable, it harvests the item and deletes it from the farm
      if(m_farm.at(j) ->GetIsHarvestable()){
        m_farm.at(j)->Harvest(m_money, m_food);
        delete m_farm.at(j);
        m_farm.erase(m_farm.begin() + j);
      //if the item is not harvestable, it increments the counter
      } else {
        j++;
      }
      }
    //if the food is less than 0, it displays the message and exits the loop
    Status();
    m_season++;
    }
  }

//Status function for the farm class, it displays the status of the farm
void Farm::Status() {
  cout << "**** Farm Status ****" << endl;
  cout << "Food: " << m_food << endl;
  cout << "Money: " << m_money << endl;
  cout << "Season: " << m_season << endl;
  cout << "Agricultural Items:" << endl;
  //if the farm is empty, it displays the message
  if(m_farm.size() == 0) {
    cout << "None" << endl;
  } else {
    for(unsigned int i = 0; i < m_farm.size(); i++) {
      (*m_farm.at(i)) << cout << endl;
    }
  }
  cout << "*********************" << endl;
}

//StartSimulation function for the farm class, it starts the simulation and displays the message
void Farm::StartSimulation() {
  cout << "Welcome to the Farm Together Simulator!" << endl;
  int choice = 0;
  int numSeasons = 0;
  //if the choice is not 5, it displays the menu and gets the choice of the user
  do {
    choice = Menu();
    //if the choice is 1, it gets the type of the item and adds it to the farm
    if (choice == 1) {
      int type = ChooseItem();
      AddItem(type, 1);
    //if the choice is 2, it adds two of each item to the farm
    } else if(choice == 2) {
      AddItem(1, 2);
      AddItem(2, 2);
      AddItem(3, 2);
    //if the choice is 3, it gets the number of seasons and ticks the farm
    } else if(choice == 3) {
      cout << "How many seasons to simulate?" << endl;
      cin >> numSeasons;
      Tick(numSeasons);
    //if the choice is 4, it displays the status of the farm
    }else if(choice == 4) {
      Status();
    //if the choice is 5, it displays the message and exits the loop
    }else if(choice == 5) {
      cout << "Thanks for farming! Goodbye." << endl;
    }
    
    } while (choice != 5);
    }
  

