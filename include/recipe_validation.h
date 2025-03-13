#ifndef RECIPE_VALIDATION_H
#define RECIPE_VALIDATION_H

// Function prototypes for validation
int validateRecipeName(const char *);
int validateRecipeDescription(const char *);
int validateTimeToPrepare(const int *);
int validateTimeToCook(const int *);
int validateNumOfIngredients(const int *);
int validateIngredient(const char *);
int validateNumOfInstructions(const int *);
int validateInstruction(const char *);

#endif  // RECIPE_VALIDATION_H
