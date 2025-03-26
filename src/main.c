// Author: Raphael Maagma
// Date: '24
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Food log functions
#include "food_log.c"
#include "food_validation.c"
// Recipe functions
#include "recipe.c"
#include "recipe_validation.c"

// User functions
#include "user.c"
#include "user_input_validation.c"

// Menu functions
#include "menu.c"

int main()
{
    FoodLog foodLogs[MAX_FOOD_LOG];  // Array to store food logs
    int foodCount = 0;               // Counter for food logs

    Recipe recipeList[MAX_RECIPE];  // Array to store recipes
    int recipeCount = 0;            // Counter for recipes

    UserCredentials loggedInUser;

    int userChoice;
    int exitFlag = 0;  // Control variable for exiting

    registerUser(&loggedInUser);
    loginToUserAccount(&loggedInUser);

    do
    {
        displayMainMenu();
        scanf("%d", &userChoice);
        while (getchar() != '\n');  // Clear the input buffer

        switch (userChoice)
        {
            case 1:  // User Management
                displayUserSubMenu(foodLogs, foodCount, recipeList, recipeCount, &loggedInUser);
                break;
            case 2:  // Food Log Management
                displayFoodLogSubMenu(foodLogs, &foodCount, loggedInUser);
                break;
            case 3:  // Recipe Management
                displayRecipeSubMenu(recipeList, &recipeCount, loggedInUser);
                break;
            case 4:  // Export/Import Data
                displayExportImportSubMenu();
                break;
            case 5:  // Exit option
                if (displayExitMenu() == 1)
                {
                    exitFlag = 1;  // Set exit flag to break loop
                }
                break;  // Stay in loop if exit is canceled
            default:
                printf("\nInvalid choice! Please enter a number between 1-5.\n");
                break;
        }
    } while (exitFlag == 0);  // Loop until exit is confirmed

    return 0;  // Program exits only here
}