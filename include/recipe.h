#ifndef RECIPE_H
#define RECIPE_H

#include "data_structures.h"

// Function prototypes for adding of recipe
void addRecipe(Recipe[], int *, UserCredentials);

// Function prototypes to get specific recipe details
void getRecipeName(Recipe *);
void getRecipeDescription(Recipe *);
void getTimeToPrepare(Recipe *);
void getTimeToCook(Recipe *);
void getNumOfIngredients(Recipe *);
void getIngredients(Recipe *);
void getNumOfInstructions(Recipe *);
void getInstructions(Recipe *);

// Function prototypes to display recipe details
void displayRecipeDetails(Recipe *);
void displayAllRecipes(Recipe[], int);

// Function prototype to wrap recipe text
void wrapRecipeText(const char *, int, int);

// Function prototypes to modify, delete, and search recipe logs
void searchRecipes(Recipe[], int);
void modifyRecipe(Recipe[], int *);
void deleteRecipe(Recipe[], int *);
void searchRecipe(Recipe[], int);

// Function prototype to find the index of a recipe
int findRecipeIndex(Recipe[], int, char[]);

#endif  // RECIPE_H