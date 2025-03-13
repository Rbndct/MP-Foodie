#include "food_log.h"

#include <limits.h>
#include <stdio.h>

#include "data_structures.h"
#include "food_validation.h"

// Function to check if the food log contains a duplicate food name
void isFoodLogDuplicate(FoodLog food_log[], int count, const char *food_name, int *isDuplicate)
{
    *isDuplicate = 0;  // Default is no duplicate
    for (int i = 0; i < count; i++)
    {
        if (strcmp(food_log[i].food_name, food_name) == 0)
        {
            *isDuplicate = 1;  // Found duplicate, no need to exit the loop
        }
    }
}

void addFoodLog(FoodLog food_log[], int *count)
{
    FoodLog newLog;
    int isDuplicate = 0;  // Variable to track duplicate status

    printf("\nAdd Food Log\n");
    getFoodName(&newLog);
    getFoodType(&newLog);
    getTimesEaten(&newLog);
    getDateFirstTried(&newLog);
    getLocationFirstTried(&newLog);
    getFoodDescription(&newLog);

    // Check for duplicates using the function
    isFoodLogDuplicate(food_log, *count, newLog.food_name, &isDuplicate);

    if (isDuplicate)
    {
        printf("\nError: Duplicate food name not allowed.\n");
    }
    else
    {
        // Store new entry
        food_log[*count] = newLog;
        (*count)++;  // Increment food count
        printf("\nFood log added successfully!\n");
    }
}

void getFoodName(FoodLog *food_log)
{
    do
    {
        printf("\nEnter food name: ");
        scanf("%50[^\n]", food_log->food_name);
        while (getchar() != '\n');  // Clear the input buffer
    } while (!validateFoodName(food_log->food_name));
}

void getFoodType(FoodLog *food_log)
{
    do
    {
        printf("\nEnter food type: ");
        printf("a - appetizer, m - main course, d - dessert\n");
        scanf("%c", &food_log->food_type);  // Note the space before %c to skip any whitespace
        while (getchar() != '\n');          // Clear the input buffer
    } while (!validateFoodType(&food_log->food_type));
}

void getTimesEaten(FoodLog *food_log)
{
    int result;
    int temp;

    do
    {
        printf("\nEnter times eaten: ");
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
    } while (temp == -1 || !validateTimesEaten(&temp));

    // Assign after validation
    food_log->times_eaten = temp;
}

void getDateFirstTried(FoodLog *food_log)
{
    do
    {
        printf("\nEnter date first tried (MM/DD/YYYY): ");
        scanf("%10s", food_log->date_first_tried);
        while (getchar() != '\n');
    } while (!validateDateFirstTried(food_log->date_first_tried));
}

void getLocationFirstTried(FoodLog *food_log)
{
    do
    {
        printf("\nEnter location first tried: ");
        scanf("%30[^\n]", food_log->location_first_tried);
        while (getchar() != '\n');
    } while (!validateLocationFirstTried(food_log->location_first_tried));
}

void getFoodDescription(FoodLog *food_log)
{
    do
    {
        printf("\nEnter food description: ");
        scanf("%300[^\n]", food_log->description);
        while (getchar() != '\n');
    } while (!validateFoodDescription(food_log->description));
}

void displayAllFoodLogs(FoodLog foodLogs[], int foodCount)
{
    printf("\n--------------------------------------------------\n");

    if (foodCount == 0)
    {
        printf("                 NO FOOD LOGS AVAILABLE\n");
        printf("--------------------------------------------------\n");
    }
    else
    {
        printf("                   FOOD LOGS                     \n");
        printf("--------------------------------------------------\n");

        // Sort food logs in descending order (latest date first)
        for (int i = 0; i < foodCount - 1; i++)
        {
            for (int j = 0; j < foodCount - i - 1; j++)
            {
                if (strcmp(foodLogs[j].date_first_tried, foodLogs[j + 1].date_first_tried) < 0)
                {
                    // Swap entries
                    FoodLog temp = foodLogs[j];
                    foodLogs[j] = foodLogs[j + 1];
                    foodLogs[j + 1] = temp;
                }
            }
        }

        // Display logs
        for (int i = 0; i < foodCount; i++)
        {
            // Skip entries with empty food names
            if (strlen(foodLogs[i].food_name) > 0)
            {
                // Determine full meaning of food type
                const char *foodTypeFull;
                switch (foodLogs[i].food_type)
                {
                    case 'a':
                        foodTypeFull = "Appetizer";
                        break;
                    case 'm':
                        foodTypeFull = "Main Course";
                        break;
                    case 'd':
                        foodTypeFull = "Dessert";
                        break;
                    default:
                        foodTypeFull = "Unknown";
                        break;  // Fallback for unexpected values
                }

                printf("%-2d  %-50.50s\n", i + 1,
                       foodLogs[i].food_name);           // Food name (max 50 chars)
                printf("    Type: %s\n", foodTypeFull);  // Full meaning of food type
                printf("    Times Eaten: %-3d\n", foodLogs[i].times_eaten);
                printf("    Date First Tried: %-10.10s\n", foodLogs[i].date_first_tried);
                printf("    Location: %-30.30s\n", foodLogs[i].location_first_tried);
                printf("    Description: %-50.50s\n", foodLogs[i].description);

                // Add word wrapping for descriptions longer than 50 chars
                if (strlen(foodLogs[i].description) > 50)
                {
                    for (int j = 50; j < strlen(foodLogs[i].description); j += 50)
                    {
                        printf("                %-50.50s\n", &foodLogs[i].description[j]);
                    }
                }
                printf("--------------------------------------------------\n");
            }
        }
    }
}

// Function to display the current food log details in the same format as `displayAllFoodLogs`
void displayFoodLogDetails(FoodLog *log)
{
    printf("\n--------------------------------------------------\n");
    printf("                   FOOD LOG DETAILS              \n");
    printf("--------------------------------------------------\n");

    // Determine full meaning of food type
    const char *foodTypeFull;
    switch (log->food_type)
    {
        case 'a':
            foodTypeFull = "Appetizer";
            break;
        case 'm':
            foodTypeFull = "Main Course";
            break;
        case 'd':
            foodTypeFull = "Dessert";
            break;
        default:
            foodTypeFull = "Unknown";
            break;  // Fallback for unexpected values
    }

    printf("    Food Name: %-50.50s\n", log->food_name);  // Food name (max 50 chars)
    printf("    Type: %-20s\n", foodTypeFull);            // Full meaning of food type
    printf("    Times Eaten: %-3d\n", log->times_eaten);
    printf("    Date First Tried: %-10.10s\n", log->date_first_tried);
    printf("    Location First Tried: %-30.30s\n", log->location_first_tried);
    printf("    Description: %-50.50s\n", log->description);

    // Add word wrapping for descriptions longer than 50 chars
    if (strlen(log->description) > 50)
    {
        for (int i = 50; i < strlen(log->description); i += 50)
        {
            printf("                %-50.50s\n", &log->description[i]);
        }
    }
    printf("--------------------------------------------------\n");
}

void modifyFoodLog(FoodLog food_log[], int *count)
{
    char search_name[MAX_FOOD_NAME_LEN];
    int isFound = 0;
    int isDuplicate = 0;

    printf("\nModify Food Log\n");
    printf("Enter the food name to search for: ");
    scanf("%50s", search_name);

    // Search for the food log entry by food name
    for (int i = 0; i < *count; i++)
    {
        if (strcmp(food_log[i].food_name, search_name) == 0)
        {
            // Display the current food log details
            displayFoodLogDetails(&food_log[i]);

            // Ask if the user wants to modify the found entry
            printf("\nDo you want to modify this food log? (y/n): ");
            char confirm;
            scanf(
                " %c",
                &confirm);  // Space before %c to skip the newline character from the previous input

            if (confirm == 'y' || confirm == 'Y')
            {
                // Modify food log details
                getFoodName(&food_log[i]);
                getFoodType(&food_log[i]);
                getTimesEaten(&food_log[i]);
                getDateFirstTried(&food_log[i]);
                getLocationFirstTried(&food_log[i]);
                getFoodDescription(&food_log[i]);

                // Check if the new food name is a duplicate
                isFoodLogDuplicate(food_log, *count, food_log[i].food_name, &isDuplicate);

                if (isDuplicate)
                {
                    printf("\nError: Duplicate food name not allowed. Modification aborted.\n");
                }
                else
                {
                    // Proceed with the modification
                    printf("\nFood log updated successfully!\n");
                }
            }
            else
            {
                printf("\nModification canceled. No changes were made.\n");
            }

            isFound = 1;
            // If the food log is found, isFound will be set to 1, and the loop will complete
        }
    }

    // Check if no food log was found
    if (!isFound)
    {
        printf("\nError: Food log not found.\n");
    }
}

void deleteFoodLog(FoodLog food_log[], int *count)
{
    char search_name[MAX_FOOD_NAME_LEN];
    int isFound = 0;

    printf("\nDelete Food Log\n");
    printf("Enter the food name to search for: ");
    scanf("%50s", search_name);

    // Search for the food log entry by food name
    for (int i = 0; i < *count; i++)
    {
        if (strcmp(food_log[i].food_name, search_name) == 0)
        {
            // Display the current food log details to be deleted
            displayFoodLogDetails(&food_log[i]);

            // Ask if the user wants to delete the found entry
            printf("\nDo you want to delete this food log? (y/n): ");
            char confirm;
            scanf(
                " %c",
                &confirm);  // Space before %c to skip the newline character from the previous input

            if (confirm == 'y' || confirm == 'Y')
            {
                // Proceed with deleting the food log
                // Shift all subsequent food logs to remove the current entry
                for (int j = i; j < *count - 1; j++)
                {
                    food_log[j] = food_log[j + 1];
                }

                (*count)--;  // Decrement the food log count
                printf("\nFood log deleted successfully!\n");
            }
            else
            {
                printf("\nDeletion canceled. No changes were made.\n");
            }

            isFound = 1;
            // If the food log is found, isFound will be set to 1, and the loop will complete
        }
    }

    // Check if no food log was found
    if (!isFound)
    {
        printf("\nError: Food log not found.\n");
    }
}

void searchFoodLog(FoodLog food_log[], int count)
{
    char search_name[MAX_FOOD_NAME_LEN];
    int foundIndex = -1;  // Variable to store found index

    printf("\nSearch Food Log\n");
    printf("Enter the food name to search for: ");
    scanf("%50s", search_name);

    // Search for the food log entry by food name
    for (int i = 0; i < count; i++)
    {
        if (strcmp(food_log[i].food_name, search_name) == 0)
        {
            foundIndex = i;
        }
    }

    if (foundIndex != -1)
    {
        printf("\nFood Log Found:\n");
        displayFoodLogDetails(&food_log[foundIndex]);
    }
    else
    {
        printf("\nNo such food has been logged.\n");
    }

    printf("\nPress any key to continue...");
    getchar();  // Wait for user input before returning to the main menu
    getchar();
}
