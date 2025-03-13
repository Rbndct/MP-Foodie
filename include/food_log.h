#ifndef FOOD_LOG_H
#define FOOD_LOG_H

#include "data_structures.h"

// Function prototype to add a new food log entry
void addFoodLog(FoodLog[], int *);

// Function prototypes to get specific food log details
void getFoodName(FoodLog *);
void getFoodType(FoodLog *);
void getTimesEaten(FoodLog *);
void getDateFirstTried(FoodLog *);
void getLocationFirstTried(FoodLog *);
void getFoodDescription(FoodLog *);

void displayAllFoodLogs(FoodLog[], int);
void wrapText(const char *, int);

void modifyFoodLog(FoodLog[], int *);
void displayFoodLogDetails(FoodLog *);
void deleteFoodLog(FoodLog[], int *);
void searchFoodLog(FoodLog[], int);
#endif  // FOOD_LOG_H
