#ifndef FOOD_VALIDATION_H
#define FOOD_VALIDATION_H

// Function prototypes for validation
int validateFoodName(char *);
int validateFoodType(char);
int validateTimesEaten(const int *);
int validateDateFirstTried(const char *);
int validateLocationFirstTried(char *);
int validateFoodDescription(char *);

// Function prototypes to get current year
int isLeapYear(int);
int getCurrentYear();

#endif  // FOOD_VALIDATION_H
