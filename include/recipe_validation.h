#ifndef RECIPE_VALIDATION_H
#define RECIPE_VALIDATION_H

// Function prototypes for validation
int validateRecipeName(char *);
int validateRecipeDescription(char *);
int validateTimeToPrepare(const int *);
int validateTimeToCook(const int *);
int validateNumOfIngredients(const int *);
int validateIngredient(char *);
int validateNumOfInstructions(const int *);
int validateInstruction(char *);

#endif  // RECIPE_VALIDATION_H
