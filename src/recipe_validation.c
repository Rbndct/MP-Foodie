#include "recipe_validation.h"

#include <ctype.h>
#include <stdio.h>
#include <string.h>

#include "data_structures.h"

int validateRecipeName(const char *recipe_name)
{
    // Get recipe name length
    int recipeName_len = strlen(recipe_name);
    int isValid = 1;

    // Check if recipe name is between 3 and 50 characters
    if (recipeName_len < 3 || recipeName_len > 50)
    {
        isValid = 0;
        printf("Recipe name should be between 3 and 50 characters.\n");
    }

    // Check if recipe name contains only alphanumeric characters
    for (int i = 0; i < recipeName_len; i++)
    {
        if (!isalnum(recipe_name[i]) && recipe_name[i] != ' ')
        {
            printf("Recipe name should only contain alphanumeric characters.\n");
            isValid = 0;
        }
    }
    return isValid;
}

int validateRecipeDescription(const char *recipe_description)
{
    // Get recipe description length
    int recipeDescription_len = strlen(recipe_description);
    int isValid = 1;

    // Check if recipe description is between 1 and 160 characters
    if (recipeDescription_len < 0 || recipeDescription_len > 160)
    {
        isValid = 0;
        printf("Recipe description should be between 1 and 160 characters.\n");
    }
    return isValid;
}

int validateTimeToPrepare(const int *time_to_prepare)
{
    int isValid = 1;

    // Check if it is a positive integer
    if (*time_to_prepare < 0)
    {
        isValid = 0;
        printf("Time to prepare should be a positive integer.\n");
    }
    return isValid;
}

int validateTimeToCook(const int *time_to_cook)
{
    int isValid = 1;

    // Check if it is a positive integer
    if (*time_to_cook < 0)
    {
        isValid = 0;
        printf("Time to cook should be a positive integer.\n");
    }
    return isValid;
}

int validateNumOfIngredients(const int *num_of_ingredients)
{
    int isValid = 1;

    // Check if it is a positive integer
    if (*num_of_ingredients < 0 || *num_of_ingredients > MAX_RECIPE_INGREDIENTS)
    {
        isValid = 0;
        printf("Number of ingredients should be a positive integer.\n");
    }
    return isValid;
}

int validateIngredient(const char *ingredient)
{
    // Get ingredient length
    int ingredient_len = strlen(ingredient);
    int isValid = 1;

    // Check if ingredient is between 1 and 80 characters
    if (ingredient_len < 0 || ingredient_len > 80)
    {
        isValid = 0;
        printf("Ingredient should be between 3 and 80 characters.\n");
    }

    return isValid;
}

int validateNumOfInstructions(const int *num_of_instructions)
{
    int isValid = 1;

    // Check if it is a positive integer
    if (*num_of_instructions < 0 || *num_of_instructions > MAX_RECIPE_INSTRUCTIONS)
    {
        isValid = 0;
        printf("Number of instructions should be a positive integer.\n");
    }
    return isValid;
}

int validateInstruction(const char *instruction)
{
    // Get instruction length
    int instruction_len = strlen(instruction);
    int isValid = 1;

    // Check if instruction is between 1 and 100 characters
    if (instruction_len < 0 || instruction_len > MAX_INSTRUCTION_LEN - 1)
    {
        isValid = 0;
        printf("Instruction should be between 1 and 100 characters.\n");
    }

    return isValid;
}