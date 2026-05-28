// Title: AgItem.cpp
// Author: Tahmid Khan
// Date: 11/08/2025
// Description: Implementation of the AgItem parent class (abstract class for all agricultural items)

#include "AgItem.h"

// Creates an AgItem with size 0
AgItem::AgItem() {
  m_size = 0;
  m_worth = BASE_WORTH;
  m_isHarvestable = false;
}


// Creates an AgItem with size, worth, and isHarvestable passed in as parameters
// Preconditions: size >= 0, worth >= 0, isHarvestable is true or false
AgItem::AgItem(int size, int worth, bool isHarvestable) {
  m_size = size;
  m_worth = worth;
  m_isHarvestable = isHarvestable;
}


// Deletes an AgItem
AgItem::~AgItem() {
}


// Returns the size of the AgItem
int AgItem::GetSize() {
  return m_size;
}

// Returns the worth of the AgItem
int AgItem::GetWorth() {
  return m_worth;
}

// Returns whether the AgItem is harvestable
bool AgItem::GetIsHarvestable() {
  return m_isHarvestable;
}

// Sets the size of the AgItem
void AgItem::SetSize(int size) {
  m_size = size;
}

// Sets the worth of the AgItem
void AgItem::SetWorth(int worth) {
  m_worth = worth;
}

// Sets whether the AgItem is harvestable
void AgItem::SetIsHarvestable(bool isHarvestable) {
  m_isHarvestable = isHarvestable;
}
