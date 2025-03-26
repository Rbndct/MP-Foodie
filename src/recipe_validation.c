#include "recipe_validation.h"

#include <ctype.h>
#include <stdio.h>
#include <string.h>

#include "data_structures.h"

int validateRecipeName(char *recipe_name)
{
    int isValid = 1;
    int len = strlen(recipe_name);
    if (len < 3 || len > MAX_RECIPE_NAME_LEN - 1)
    {
        printf("Recipe name should be between 3 and 50 characters.\n");
        isValid = 0;
    }
    int i = 0;
    while (i < len && isValid)
    {
        if (!isalnum(recipe_name[i]) && recipe_name[i] != ' ')
        {
            printf("Recipe name should only contain alphanumeric characters.\n");
            isValid = 0;
        }
        i++;
    }
    int ch, overflow = 0;
    while ((ch = getchar()) != '\n' && ch != EOF)
    {
        overflow = 1;
    }
    if (overflow)
    {
        printf("Input was too long! Only 50 characters allowed.\n");
        recipe_name[0] = '\0';
        isValid = 0;
    }
    return isValid;
}

int validateRecipeDescription(char *recipe_description)
{
    int isValid = 1;
    int len = strlen(recipe_description);

    if (len < 1 || len > MAX_RECIPE_DESCRIPTION_LEN - 1)
    {
        printf("Recipe description should be between 1 and 160 characters.\n");
        isValid = 0;
    }

    int ch, overflow = 0;
    while ((ch = getchar()) != '\n' && ch != EOF)
    {
        overflow = 1;
    }

    if (overflow)
    {
        printf("Input was too long! Only 160 characters allowed.\n");
        recipe_description[0] = '\0';
        isValid = 0;
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

int validateIngredient(char *ingredient)
{
    int isValid = 1;
    int len = strlen(ingredient);

    if (len < 1 || len > MAX_INGREDIENT_LEN - 1)
    {
        printf("Ingredient should be between 1 and 80 characters.\n");
        isValid = 0;
    }

    int ch, overflow = 0;
    while ((ch = getchar()) != '\n' && ch != EOF)
    {
        overflow = 1;
    }

    if (overflow)
    {
        printf("Input was too long! Only 80 characters allowed.\n");
        ingredient[0] = '\0';
        isValid = 0;
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

int validateInstruction(char *instruction)
{
    int isValid = 1;
    int len = strlen(instruction);

    if (len < 1 || len > MAX_INSTRUCTION_LEN - 1)
    {
        printf("Instruction should be between 1 and %d characters.\n", MAX_INSTRUCTION_LEN - 1);
        isValid = 0;
    }

    int ch, overflow = 0;
    while ((ch = getchar()) != '\n' && ch != EOF)
    {
        overflow = 1;
    }

    if (overflow)
    {
        printf("Input was too long! Only %d characters allowed.\n", MAX_INSTRUCTION_LEN - 1);
        instruction[0] = '\0';
        isValid = 0;
    }

    return isValid;
}