#ifndef FOOD_LOG_H
#define FOOD_LOG_H

#include "data_structures.h"

// Function prototype to add a new food log entry
void addFoodLog(FoodLog[], int *, UserCredentials);

// Function prototypes to get specific food log details
void getFoodName(FoodLog *);
void getFoodType(FoodLog *);
void getTimesEaten(FoodLog *);
void getDateFirstTried(FoodLog *);
void getLocationFirstTried(FoodLog *);
void getFoodDescription(FoodLog *);

// Function prototypes to display food log entries
void displayFoodLogDetails(FoodLog *);
void displayAllFoodLogs(FoodLog[], int);

// Function prototype to wrap food log text
void wrapFoodText(const char *, int);

// Function prototypes to modify, delete, and search food logs
void modifyFoodLog(FoodLog[], int *);
void deleteFoodLog(FoodLog[], int *);
void searchFoodLog(FoodLog[], int);

// Function prototype to find the index of a food log
int findFoodLogIndex(FoodLog[], int, char[]);

#endif  // FOOD_LOG_H
