#ifndef RECIPE_H
#define RECIPE_H

#include "data_structures.h"

// Function prototypes for adding of recipe
void addRecipe(Recipe *);

// Function prototypes to get specific recipe details
void getRecipeName(Recipe *);
void getRecipeDescription(Recipe *);
void getTimeToPrepare(Recipe *);
void getTimeToCook(Recipe *);
void getNumOfIngredients(Recipe *);
void getIngredients(Recipe *);
void getNumOfInstructions(Recipe *);
void getInstructions(Recipe *);

#endif  // RECIPE_H