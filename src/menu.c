#include "menu.h"

#include <stdio.h>

#include "data_structures.h"

void displayMainMenu()
{
    printf("\n|%38s|\n", "--------------------------------------");
    printf("|%11sFOODIE APP MENU%12s|\n", "", "");
    printf("|%38s|\n", "--------------------------------------");
    printf("| %-3s -> %-29s |\n", "1.", "User Management");
    printf("| %-3s -> %-29s |\n", "2.", "Food Log Management");
    printf("| %-3s -> %-29s |\n", "3.", "Recipe Management");
    printf("| %-3s -> %-29s |\n", "4.", "Export/Import Data");
    printf("| %-3s -> %-29s |\n", "5.", "Exit");
    printf("|%38s|\n", "--------------------------------------");
    printf("%28s", "Enter your choice:");
}

void displayUserSubMenu()
{
    int userChoice;
    int validInput;

    do
    {
        printf("\n|%38s|\n", "--------------------------------------");
        printf("|%9sUSER MANAGEMENT MENU%9s|\n", "", "");
        printf("|%38s|\n", "--------------------------------------");
        printf("| %-3s -> %-29s |\n", "1.", "Display User");
        printf("| %-3s -> %-29s |\n", "2.", "View All User Entries");
        printf("| %-3s -> %-29s |\n", "0.", "Return to Main Menu");
        printf("|%38s|\n", "--------------------------------------");
        printf("%28s", "Enter your choice:");

        validInput = scanf("%d", &userChoice);
        while (getchar() != '\n');  // Clear input buffer

        if (validInput != 1)  // If input is not a number
        {
            printf("\nInvalid input! Please enter a number between 0-2.\n");
        }
        else
        {
            switch (userChoice)
            {
                case 1:
                    printf("\nDisplaying user details...\n");
                    break;
                case 2:
                    printf("\nViewing all user entries...\n");
                    break;
                case 0:
                    printf("\nReturning to Main Menu...\n");
                    break;
                default:
                    printf("\nInvalid choice! Please enter a number between 0-2.\n");
                    break;
            }
        }

        if (userChoice != 0)
        {
            printf("\nPress Enter to continue...");
            while (getchar() != '\n');  // Wait for user input before looping again
        }

    } while (userChoice != 0);
}
void displayFoodLogSubMenu(FoodLog *foodLogs, int *foodCount)
{
    int userChoice;
    int validInput;

    do
    {
        printf("\n|%38s|\n", "--------------------------------------");
        printf("|%7sFOOD LOG MANAGEMENT MENU%7s|\n", "", "");
        printf("|%38s|\n", "--------------------------------------");
        printf("| %-3s -> %-29s |\n", "1.", "Add Food Log");
        printf("| %-3s -> %-29s |\n", "2.", "Modify Food Log");
        printf("| %-3s -> %-29s |\n", "3.", "Delete Food Log");
        printf("| %-3s -> %-29s |\n", "4.", "Display All Food Logs");
        printf("| %-3s -> %-29s |\n", "5.", "Search Food Log");
        printf("| %-3s -> %-29s |\n", "0.", "Return to Main Menu");
        printf("|%38s|\n", "--------------------------------------");
        printf("%28s", "Enter your choice:");

        validInput = scanf("%d", &userChoice);
        while (getchar() != '\n');  // Clear input buffer

        if (validInput != 1)  // If input is not a number
        {
            printf("\nInvalid input! Please enter a number between 0-5.\n");
        }
        else
        {
            switch (userChoice)
            {
                void searchFoodLog(FoodLog[], int);
                case 1:
                    if (*foodCount < MAX_FOOD_LOG)  // Check if there's space for a new entry
                    {
                        addFoodLog(foodLogs, foodCount);
                        (*foodCount)++;  // Increment food count
                    }
                    else
                    {
                        printf("\nFood log is full! Cannot add more entries.\n");
                    }
                    break;
                case 2:
                    modifyFoodLog(foodLogs, foodCount);
                    break;
                case 3:
                    deleteFoodLog(foodLogs, foodCount);
                    break;
                case 4:
                    displayAllFoodLogs(foodLogs, *foodCount);
                    break;
                case 5:
                    searchFoodLog(foodLogs, *foodCount);
                    break;
                case 0:
                    printf("\nReturning to Main Menu...\n");
                    break;
                default:
                    printf("\nInvalid choice! Please enter a number between 0-5.\n");
                    break;
            }
        }

        if (userChoice != 0)
        {
            printf("\nPress Enter to continue...");
            while (getchar() != '\n');  // Wait for user input before looping again
        }

    } while (userChoice != 0);
}

void displayRecipeSubMenu()
{
    int userChoice;
    int validInput;

    do
    {
        printf("\n|%38s|\n", "--------------------------------------");
        printf("|%8sRECIPE MANAGEMENT MENU%8s|\n", "", "");
        printf("|%38s|\n", "--------------------------------------");
        printf("| %-3s -> %-29s |\n", "1.", "Add Recipe");
        printf("| %-3s -> %-29s |\n", "2.", "Modify Recipe");
        printf("| %-3s -> %-29s |\n", "3.", "Delete Recipe");
        printf("| %-3s -> %-29s |\n", "4.", "Display All Recipes");
        printf("| %-3s -> %-29s |\n", "5.", "Search Recipe");
        printf("| %-3s -> %-29s |\n", "0.", "Return to Main Menu");
        printf("|%38s|\n", "--------------------------------------");
        printf("%28s", "Enter your choice:");

        validInput = scanf("%d", &userChoice);
        while (getchar() != '\n');  // Clear input buffer

        if (validInput != 1)  // If input is not a number
        {
            printf("\nInvalid input! Please enter a number between 0-5.\n");
        }
        else
        {
            switch (userChoice)
            {
                case 1:
                    printf("\nAdding a new recipe...\n");
                    break;
                case 2:
                    printf("\nModifying an existing recipe...\n");
                    break;
                case 3:
                    printf("\nDeleting a recipe...\n");
                    break;
                case 4:
                    printf("\nDisplaying all recipes...\n");
                    break;
                case 5:
                    printf("\nSearching for a recipe...\n");
                    break;
                case 0:
                    printf("\nReturning to Main Menu...\n");
                    break;
                default:
                    printf("\nInvalid choice! Please enter a number between 0-5.\n");
                    break;
            }
        }

        if (userChoice != 0)
        {
            printf("\nPress Enter to continue...");
            while (getchar() != '\n');  // Wait for user input before looping again
        }

    } while (userChoice != 0);
}

void displayExportImportSubMenu()
{
    int userChoice;
    int validInput;

    do
    {
        printf("\n|%38s|\n", "--------------------------------------");
        printf("|%7sEXPORT & IMPORT DATA MENU%6s|\n", "", "");
        printf("|%38s|\n", "--------------------------------------");
        printf("| %-3s -> %-29s |\n", "1.", "Export Data");
        printf("| %-3s -> %-29s |\n", "2.", "Import Data");
        printf("| %-3s -> %-29s |\n", "0.", "Return to Main Menu");
        printf("|%38s|\n", "--------------------------------------");
        printf("%28s", "Enter your choice:");

        validInput = scanf("%d", &userChoice);
        while (getchar() != '\n');  // Clear input buffer

        if (validInput != 1)  // If input is not a number
        {
            printf("\nInvalid input! Please enter a number between 0-2.\n");
        }
        else
        {
            switch (userChoice)
            {
                case 1:
                    printf("\nExporting data...\n");
                    break;
                case 2:
                    printf("\nImporting data...\n");
                    break;
                case 0:
                    printf("\nReturning to Main Menu...\n");
                    break;
                default:
                    printf("\nInvalid choice! Please enter a number between 0-2.\n");
                    break;
            }
        }

        if (userChoice != 0)
        {
            printf("\nPress Enter to continue...");
            while (getchar() != '\n');  // Wait for user input before re-displaying menu
        }

    } while (userChoice != 0);
}

int displayExitMenu()
{
    char userChoice;
    int exitStatus = 0;  // 0 = Cancel Exit, 1 = Confirm Exit

    do
    {
        printf("\n|%38s|\n", "--------------------------------------");
        printf("|%14sEXIT MENU%15s|\n", "", "");
        printf("|%38s|\n", "--------------------------------------");
        printf("|%4sAre you sure you want to exit?%4s|\n", "", "");
        printf("|%8s( Y - Yes  |  N - No )%8s|\n", "", "");
        printf("|%38s|\n", "--------------------------------------");
        printf("%28s", "Enter your choice: ");

        scanf(" %c", &userChoice);
        while (getchar() != '\n');  // Clear input buffer

        userChoice = toupper(userChoice);  // Convert input to uppercase

        if (userChoice == 'Y')
        {
            printf("\nExiting program...\n");
            exitStatus = 1;  // Confirm exit
        }
        else if (userChoice == 'N')
        {
            printf("\nReturning to Main Menu...\n");
            exitStatus = 0;  // Cancel exit
        }
        else
        {
            printf("\nInvalid choice! Please enter 'Y' for Yes or 'N' for No.\n");
        }

    } while (userChoice != 'Y' && userChoice != 'N');  // Loop until valid input

    return exitStatus;  // Return final exit status
}