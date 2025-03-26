#ifndef MENU_H
#define MENU_H
#include "data_structures.h"

// Function prototypes for displaying menus
void displayMainMenu();
void displayUserSubMenu(FoodLog[], int, Recipe[], int, UserCredentials *);

// Function prototypes for displaying sub-menus
void displayFoodLogSubMenu(FoodLog[], int *, UserCredentials);
void displayRecipeSubMenu(Recipe[], int *, UserCredentials);
void displayExportImportSubMenu();

// Function prototype for displaying exit menu
int displayExitMenu();

#endif  // MENU_H
