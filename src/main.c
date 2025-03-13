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

    int userChoice;
    int exitFlag = 0;  // Control variable for exiting

    do
    {
        displayMainMenu();
        scanf("%d", &userChoice);
        while (getchar() != '\n');  // Clear the input buffer

        switch (userChoice)
        {
            case 1:  // User Management
                displayUserSubMenu();
                break;
            case 2:  // Food Log Management
                displayFoodLogSubMenu(foodLogs, &foodCount);
                break;
            case 3:  // Recipe Management
                displayRecipeSubMenu();
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