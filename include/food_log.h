#ifndef FOOD_LOG_H
#define FOOD_LOG_H

#include "data_structures.h"

// Function to add a new food log entry
void addFoodLog(FoodLog *);

// Functions to get specific food log details
void getFoodName(FoodLog *);
void getFoodType(FoodLog *);
void getTimesEaten(FoodLog *);
void getDateFirstTried(FoodLog *);
void getLocationFirstTried(FoodLog *);
void getFoodDescription(FoodLog *);

#endif  // FOOD_LOG_H
