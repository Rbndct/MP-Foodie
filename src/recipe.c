
#include "recipe.h"

#include <limits.h>
#include <stdio.h>

#include "data_structures.h"
#include "recipe_validation.h"

void addRecipe(Recipe *recipe)
{
    printf("\n Add a New Recipe\n");
    getRecipeName(recipe);
    getRecipeDescription(recipe);
    getTimeToPrepare(recipe);
    getTimeToCook(recipe);
    getNumOfIngredients(recipe);
    getIngredients(recipe);
    getNumOfInstructions(recipe);
    getInstructions(recipe);
}

void getRecipeName(Recipe *recipe)
{
    do
    {
        printf("\nEnter recipe name: ");
        scanf("%50[^\n]", recipe->recipe_name);
        while (getchar() != '\n');  // Clear the input buffer
    } while (!validateRecipeName(recipe->recipe_name));
}

void getRecipeDescription(Recipe *recipe)
{
    do
    {
        printf("\nEnter overall description of the recipe: ");
        scanf("%160[^\n]", recipe->recipe_description);
        while (getchar() != '\n');  // Clear the input buffer
    } while (!validateRecipeDescription(recipe->recipe_description));
}

void getTimeToPrepare(Recipe *recipe)
{
    int result;
    int temp;

    do
    {
        printf("\nEnter time to prepare (in minutes): ");

        result = scanf("%d", &temp);

        // Clear input buffer
        while (getchar() != '\n');

        // If scanf failed (invalid input), prompt again
        if (result != 1)
        {
            printf("Please enter a valid  integer.\n");
            printf("Max value is %d.\n", INT_MAX);
            temp = -1;  // Force re-entry
        }
    } while (temp == -1 || !validateTimeToPrepare(&temp));
    recipe->time_to_prepare = temp;
}

void getTimeToCook(Recipe *recipe)
{
    int result;
    int temp;

    do
    {
        printf("\nEnter time to cook (in minutes): ");
        result = scanf("%d", &temp);

        // Clear input buffer
        while (getchar() != '\n');

        // If scanf failed (invalid input), prompt again
        if (result != 1)
        {
            printf("Please enter a valid  integer.\n");
            printf("Max value is %d.\n", INT_MAX);
            temp = -1;  // Force re-entry
        }
    } while (temp == -1 || !validateTimeToCook(&temp));
    recipe->time_to_cook = temp;
}

void getNumOfIngredients(Recipe *recipe)
{
    int result;
    long long temp;

    do
    {
        printf("\nEnter number of ingredients (Max is %d): ", MAX_RECIPE_INGREDIENTS);

        result = scanf("%lld", &temp);

        // Clear input buffer
        while (getchar() != '\n');

        // If scanf failed (invalid input), prompt again
        if (result != 1)
        {
            printf("Please enter a valid number value.\n");
            temp = -1;  // Ensure it fails validation
        }
        else if (temp > INT_MAX)
        {
            printf("Input exceeds the maximum value of %d.\n", INT_MAX);
            temp = -1;  // Force re-entry
        }
        else
        {
            recipe->num_of_ingredients = (int) temp;  // Safe assignment
        }

    } while (!validateNumOfIngredients(&recipe->num_of_ingredients));
}

void getIngredients(Recipe *recipe)
{
    for (int i = 0; i < recipe->num_of_ingredients; i++)
    {
        do
        {
            printf("\nEnter ingredient %d: ", i + 1);
            scanf("%80[^\n]", recipe->ingredients[i]);
            while (getchar() != '\n');  // Clear the input buffer
        } while (!validateIngredient(recipe->ingredients[i]));
    }
}

void getNumOfInstructions(Recipe *recipe)
{
    int result;
    long long temp;  // Temporary variable to check for overflow

    do
    {
        printf("\nEnter number of instructions (Max is %d): ", MAX_RECIPE_INSTRUCTIONS);

        result = scanf("%lld", &temp);

        // Clear input buffer
        while (getchar() != '\n');

        // If scanf failed (invalid input), prompt again
        if (result != 1)
        {
            printf("Please enter a valid number value.\n");
            temp = -1;  // Ensure it fails validation
        }
        else if (temp > INT_MAX)
        {
            printf("Input exceeds the maximum value of %d.\n", INT_MAX);
            temp = -1;  // Force re-entry
        }
        else
        {
            recipe->num_of_instructions = (int) temp;  // Safe assignment
        }

    } while (!validateNumOfInstructions(&recipe->num_of_instructions));
}

void getInstructions(Recipe *recipe)
{
    for (int i = 0; i < recipe->num_of_instructions; i++)
    {
        do
        {
            printf("\nEnter instruction %d: ", i + 1);
            scanf("%100[^\n]", recipe->instructions[i]);
            while (getchar() != '\n');  // Clear the input buffer
        } while (!validateInstruction(recipe->instructions[i]));
    }
}
