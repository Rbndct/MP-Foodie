
#include "recipe.h"

#include <ctype.h>
#include <limits.h>
#include <stdio.h>

#include "data_structures.h"
#include "recipe_validation.h"

// Function to check if the recipe list contains a duplicate recipe name
void isRecipeDuplicate(Recipe recipe_list[], int count, const char *recipe_name, int *isDuplicate)
{
    *isDuplicate = 0;  // Default is no duplicate
    for (int i = 0; i < count; i++)
    {
        if (strcmp(recipe_list[i].recipe_name, recipe_name) == 0)
        {
            *isDuplicate = 1;  // Found duplicate, no need to exit the loop
        }
    }
}

void addRecipe(Recipe recipe_list[], int *count, UserCredentials UserCredentials)
{
    Recipe newRecipe;
    int isDuplicate = 0;  // Variable to track duplicate status
    int canAdd = 1;       // Flag to control whether a recipe can be added

    printf("\nAdd a New Recipe\n");

    // Check if the recipe list is already full
    if (*count >= MAX_RECIPE)
    {
        printf("\nError: Recipe list is full. Cannot add more recipes.\n");
        canAdd = 0;  // Set flag to prevent adding a new recipe
    }

    if (canAdd)  // Proceed only if there's space in the list
    {
        getRecipeName(&newRecipe);
        getRecipeDescription(&newRecipe);
        getTimeToPrepare(&newRecipe);
        getTimeToCook(&newRecipe);
        getNumOfIngredients(&newRecipe);
        getIngredients(&newRecipe);
        getNumOfInstructions(&newRecipe);
        getInstructions(&newRecipe);

        strcpy(newRecipe.username, UserCredentials.username);    // Attach logged-in username
        strcpy(newRecipe.full_name, UserCredentials.full_name);  // Attach full name of user

        // Check for duplicates using the function
        isRecipeDuplicate(recipe_list, *count, newRecipe.recipe_name, &isDuplicate);

        if (isDuplicate)
        {
            printf("\nError: Duplicate recipe name not allowed.\n");
        }
        else
        {
            // Store new entry
            recipe_list[*count] = newRecipe;
            (*count)++;  // Increment recipe count
            printf("\nRecipe added successfully!\n");
        }
    }
}

void getRecipeName(Recipe *recipe)
{
    do
    {
        printf("\nEnter recipe name: ");
        scanf(" %50[^\n]", recipe->recipe_name);
    } while (!validateRecipeName(recipe->recipe_name));
}

void getRecipeDescription(Recipe *recipe)
{
    do
    {
        printf("\nEnter overall description of the recipe: ");
        scanf(" %160[^\n]", recipe->recipe_description);
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
    int temp;

    do
    {
        printf("\nEnter number of ingredients (Max is %d): ", MAX_RECIPE_INGREDIENTS);
        result = scanf("%d", &temp);

        // Clear input buffer
        while (getchar() != '\n');

        // If scanf failed (invalid input), prompt again
        if (result != 1)
        {
            printf("Please enter a valid integer.\n");
            temp = -1;  // Force re-entry
        }
    } while (temp == -1 || !validateNumOfIngredients(&temp));

    recipe->num_of_ingredients = temp;
}

void getIngredients(Recipe *recipe)
{
    for (int i = 0; i < recipe->num_of_ingredients; i++)
    {
        do
        {
            printf("\nEnter ingredient %d: ", i + 1);
            scanf(" %80[^\n]", recipe->ingredients[i]);
        } while (!validateIngredient(recipe->ingredients[i]));
    }
}
void getNumOfInstructions(Recipe *recipe)
{
    int result;
    int temp;

    do
    {
        printf("\nEnter number of instructions (Max is %d): ", MAX_RECIPE_INSTRUCTIONS);
        result = scanf("%d", &temp);

        // Clear input buffer
        while (getchar() != '\n');

        // If scanf failed (invalid input), prompt again
        if (result != 1)
        {
            printf("Please enter a valid integer.\n");
            temp = -1;  // Force re-entry
        }
    } while (temp == -1 || !validateNumOfInstructions(&temp));

    recipe->num_of_instructions = temp;
}

void getInstructions(Recipe *recipe)
{
    for (int i = 0; i < recipe->num_of_instructions; i++)
    {
        do
        {
            printf("\nEnter instruction %d: ", i + 1);
            scanf(" %100[^\n]", recipe->instructions[i]);
        } while (!validateInstruction(recipe->instructions[i]));
    }
}

void wrapRecipeText(const char *text, int firstLineIndent, int wrappedLineIndent)
{
    int len = strlen(text);
    int start = 0;

    // Trim leading spaces
    while (isspace(text[start])) start++;

    int indent = firstLineIndent;

    while (start < len)
    {
        int end = start + 44;
        if (end >= len)
        {
            printf("%*s%s\n", indent, "", &text[start]);  // No extra space added
            break;
        }

        while (end > start && !isspace(text[end]))  // Avoid breaking words
            end--;

        if (end == start)  // No space found, force break
            end = start + 44;

        printf("%*s%.*s\n", indent, "", end - start, &text[start]);
        start = end + 1;

        // Set indent for wrapped lines
        indent = wrappedLineIndent;

        // Skip extra spaces after line break
        while (isspace(text[start])) start++;
    }
}

void displayAllRecipes(Recipe recipes[], int recipeCount)
{
    printf("\n------------------------------------------------------------\n");

    if (recipeCount == 0)
    {
        printf("                     NO RECIPES AVAILABLE                \n");
        printf("------------------------------------------------------------\n");
    }
    else
    {
        printf("                        RECIPES                           \n");
        printf("------------------------------------------------------------\n");

        // Sort recipes alphabetically by name
        for (int i = 0; i < recipeCount - 1; i++)
        {
            for (int j = 0; j < recipeCount - i - 1; j++)
            {
                if (strcmp(recipes[j].recipe_name, recipes[j + 1].recipe_name) > 0)
                {
                    Recipe temp = recipes[j];
                    recipes[j] = recipes[j + 1];
                    recipes[j + 1] = temp;
                }
            }
        }

        // Display recipes
        for (int i = 0; i < recipeCount; i++)
        {
            if (strlen(recipes[i].recipe_name) > 0)
            {
                printf("%-2d  %-58.58s\n", i + 1, recipes[i].recipe_name);
                printf("    Preparation Time: %d minutes\n", recipes[i].time_to_prepare);
                printf("    Cooking Time: %d minutes\n", recipes[i].time_to_cook);
                printf("    Description:\n");

                wrapRecipeText(recipes[i].recipe_description, 8, 8);  // Align wrapped lines
                printf("    %d Ingredients:\n", recipes[i].num_of_ingredients);
                for (int j = 0; j < recipes[i].num_of_ingredients; j++)
                {
                    printf("      - %s\n", recipes[i].ingredients[j]);
                }

                printf("    Instructions:\n");
                for (int j = 0; j < recipes[i].num_of_instructions; j++)
                {
                    printf("      %d.", j + 1);  // Align instruction number closer
                    wrapRecipeText(recipes[i].instructions[j], 4, 13);  // Align wrapped lines
                }

                printf("------------------------------------------------------------\n");
            }
        }
    }
}

int findRecipeIndex(Recipe recipes[], int recipeCount, char search_name[])
{
    int index = -1;

    for (int i = 0; i < recipeCount; i++)
    {
        if (strcmp(recipes[i].recipe_name, search_name) == 0)
        {
            index = i;
        }
    }
    return index;
}

void searchRecipes(Recipe recipes[], int recipeCount)
{
    char search_name[MAX_RECIPE_NAME_LEN];
    int foundIndex;

    printf("\nSearch Recipes\n");
    printf("\nEnter recipe name to search for: ");
    scanf(" %[^\n]", search_name);  // Allow spaces in input

    foundIndex = findRecipeIndex(recipes, recipeCount, search_name);

    if (foundIndex != -1)
    {
        printf("\n Recipe Found");
        displayRecipeDetails(&recipes[foundIndex]);
    }
    else
    {
        printf("\nNo such recipe has been logged.\n");
    }

    printf("\nPress Enter to continue...");
    while (getchar() != '\n');  // Clear input buffer
    getchar();                  // Wait for user input before returning
}

void displayRecipeDetails(Recipe *recipe)
{
    printf("\n------------------------------------------------------------\n");
    printf("                        RECIPES                           \n");
    printf("------------------------------------------------------------\n");

    printf("    %-58.58s\n", recipe->recipe_name);
    printf("    Preparation Time: %d minutes\n", recipe->time_to_prepare);
    printf("    Cooking Time: %d minutes\n", recipe->time_to_cook);
    printf("    Description:\n");

    wrapRecipeText(recipe->recipe_description, 8, 8);  // Align wrapped lines
    printf("    %d Ingredients:\n", recipe->num_of_ingredients);
    for (int j = 0; j < recipe->num_of_ingredients; j++)
    {
        printf("      - %s\n", recipe->ingredients[j]);
    }

    printf("    Instructions:\n");
    for (int j = 0; j < recipe->num_of_instructions; j++)
    {
        printf("      %d. ", j + 1);                     // Align instruction number closer
        wrapRecipeText(recipe->instructions[j], 4, 13);  // Align wrapped lines
    }

    printf("------------------------------------------------------------\n");
}

void modifyRecipe(Recipe recipes[], int *recipeCount)
{
    char search_name[MAX_RECIPE_NAME_LEN];
    int foundIndex = -1, isDuplicate = 0;

    char confirm;

    printf("\nModify Recipe\n");
    printf("Enter the recipe name to search for: ");
    scanf(" %[^\n]", search_name);  // Allow spaces in input

    foundIndex = findRecipeIndex(recipes, *recipeCount, search_name);

    if (foundIndex == -1)
    {
        printf("\nError: Recipe not found.\n");
    }
    else
    {
        // Display the current recipe details
        displayRecipeDetails(&recipes[foundIndex]);

        // Create a temporary structure to hold modifications
        Recipe temp_recipe = recipes[foundIndex];

        printf("\nEnter new details:\n");
        getRecipeName(&temp_recipe);
        getRecipeDescription(&temp_recipe);
        getTimeToPrepare(&temp_recipe);
        getTimeToCook(&temp_recipe);
        getNumOfIngredients(&temp_recipe);
        getIngredients(&temp_recipe);
        getNumOfInstructions(&temp_recipe);
        getInstructions(&temp_recipe);

        // Check for duplicate recipe name
        isRecipeDuplicate(recipes, *recipeCount, temp_recipe.recipe_name, &isDuplicate);

        if (isDuplicate)
        {
            printf("\nError: Recipe name already exists. Cannot modify.\n");
        }
        else
        {
            // Display the proposed changes for confirmation
            printf("\nProposed changes:\n");
            displayRecipeDetails(&temp_recipe);

            // Ask for confirmation in a loop until valid input ('y' or 'n') is received
            char confirm;
            int validInput = 0;
            do
            {
                printf("\nDo you want to modify this recipe? (y/n): ");
                scanf(" %c", &confirm);
                while (getchar() != '\n');  // Clear the input buffer

                if (confirm == 'y' || confirm == 'Y' || confirm == 'n' || confirm == 'N')
                {
                    validInput = 1;
                }
                else
                {
                    printf("Invalid input! Please enter only 'y' or 'n'.\n");
                }
            } while (!validInput);

            if (confirm == 'y' || confirm == 'Y')
            {
                // Replace the original recipe with the modified one
                recipes[foundIndex] = temp_recipe;
                printf("\nRecipe modified successfully.\n");
            }
            else
            {
                printf("\nModification canceled. No changes were made.\n");
            }
        }
    }
}

void deleteRecipe(Recipe recipes[], int *recipeCount)
{
    char search_name[MAX_RECIPE_NAME_LEN];
    int foundIndex = -1;
    char confirm;

    printf("\nDelete Recipe\n");
    printf("Enter the recipe name to search for: ");
    scanf(" %[^\n]", search_name);  // Allow spaces in input

    foundIndex = findRecipeIndex(recipes, *recipeCount, search_name);

    if (foundIndex == -1)
    {
        printf("\nError: Recipe not found.\n");
    }
    else
    {
        // Display the current recipe details
        displayRecipeDetails(&recipes[foundIndex]);

        // Ask for confirmation in a loop until valid input ('y' or 'n') is received
        char confirm;
        int validInput = 0;
        do
        {
            printf("\nDo you want to delete this recipe? (y/n): ");
            scanf(" %c", &confirm);
            while (getchar() != '\n');  // Clear the input buffer

            if (confirm == 'y' || confirm == 'Y' || confirm == 'n' || confirm == 'N')
            {
                validInput = 1;
            }
            else
            {
                printf("Invalid input! Please enter only 'y' or 'n'.\n");
            }
        } while (!validInput);

        if (confirm == 'y' || confirm == 'Y')
        {
            // Shift all subsequent recipes to remove the entry
            for (int i = foundIndex; i < *recipeCount - 1; i++)
            {
                recipes[i] = recipes[i + 1];
            }
            (*recipeCount)--;  // Decrement the recipe count
            printf("\nRecipe deleted successfully.\n");
        }
        else
        {
            printf("\nDeletion canceled. No changes were made.\n");
        }
    }
}

void searchRecipe(Recipe recipes[], int recipeCount)
{
    char search_name[MAX_RECIPE_NAME_LEN];
    int foundIndex = -1;

    printf("\nSearch Recipe\n");
    printf("Enter the recipe name to search for: ");
    scanf(" %[^\n]", search_name);  // Allow spaces in input

    foundIndex = findRecipeIndex(recipes, recipeCount, search_name);

    if (foundIndex != -1)
    {
        printf("\nRecipe Found:\n");
        displayRecipeDetails(&recipes[foundIndex]);
    }
    else
    {
        printf("\nNo such recipe has been logged.\n");
    }

    printf("\nPress Enter to continue...");
    while (getchar() != '\n');  // Clear input buffer
    getchar();                  // Wait for user input before returning
}