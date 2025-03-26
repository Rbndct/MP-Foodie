#include "food_log.h"

#include <ctype.h>
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

void addFoodLog(FoodLog food_log[], int *count, UserCredentials UserCredentials)
{
    FoodLog newLog;
    int isDuplicate = 0;  // Variable to track duplicate status
    int canAdd = 1;       // Flag to determine if the log can be added

    printf("\nAdd Food Log\n");

    // Check if food log is already full
    if (*count >= MAX_FOOD_LOG)
    {
        printf("\nError: Food log is full. Cannot add more entries.\n");
        canAdd = 0;  // Set flag to prevent adding new log
    }

    if (canAdd)  // Proceed only if the log is not full
    {
        getFoodName(&newLog);
        getFoodType(&newLog);
        getTimesEaten(&newLog);
        getDateFirstTried(&newLog);
        getLocationFirstTried(&newLog);
        getFoodDescription(&newLog);

        strcpy(newLog.username, UserCredentials.username);    // Attach logged-in username
        strcpy(newLog.full_name, UserCredentials.full_name);  // Attach full name of user

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
}

void getFoodName(FoodLog *food_log)
{
    do
    {
        printf("\nEnter food name: ");
        scanf(" %50[^\n]", food_log->food_name);  // Read up to 50 characters
    } while (!validateFoodName(food_log->food_name));
}

void getFoodType(FoodLog *food_log)
{
    char temp;
    int isValid = 0;

    do
    {
        printf("\nEnter food type (a - appetizer, m - main course, d - dessert): ");
        scanf(" %c", &temp);  // Add a space before %c to consume leftover newlines

        isValid = validateFoodType(temp);
        if (!isValid)
        {
            printf(
                "Invalid food type. Please enter 'a' (Appetizer), 'm' (Main Course), or 'd' "
                "(Dessert).\n");
        }
    } while (!isValid);

    food_log->food_type = temp;
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
        scanf(" %30[^\n]", food_log->location_first_tried);  // Read up to 30 characters
    } while (!validateLocationFirstTried(food_log->location_first_tried));
}

void getFoodDescription(FoodLog *food_log)
{
    do
    {
        printf("\nEnter food description: ");
        scanf(" %300[^\n]", food_log->description);  // Read up to 300 characters
    } while (!validateFoodDescription(food_log->description));
}

void displayAllFoodLogs(FoodLog foodLogs[], int foodCount)
{
    printf("\n------------------------------------------------------------\n");

    if (foodCount == 0)
    {
        printf("                     NO FOOD LOGS AVAILABLE                \n");
        printf("------------------------------------------------------------\n");
    }
    else
    {
        printf("                        FOOD LOGS                          \n");
        printf("------------------------------------------------------------\n");

        // Sort food logs in descending order (latest date first)
        for (int i = 0; i < foodCount - 1; i++)
        {
            for (int j = 0; j < foodCount - i - 1; j++)
            {
                int month1, day1, year1;
                int month2, day2, year2;

                sscanf(foodLogs[j].date_first_tried, "%d/%d/%d", &month1, &day1, &year1);
                sscanf(foodLogs[j + 1].date_first_tried, "%d/%d/%d", &month2, &day2, &year2);

                if (year1 < year2 || (year1 == year2 && month1 < month2) ||
                    (year1 == year2 && month1 == month2 && day1 < day2))
                {
                    FoodLog temp = foodLogs[j];
                    foodLogs[j] = foodLogs[j + 1];
                    foodLogs[j + 1] = temp;
                }
            }
        }

        // Display logs
        for (int i = 0; i < foodCount; i++)
        {
            if (strlen(foodLogs[i].food_name) > 0)
            {
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
                        break;
                }

                printf("%-2d  %-58.58s\n", i + 1, foodLogs[i].food_name);
                printf("    Type: %s\n", foodTypeFull);
                printf("    Times Eaten: %-3d\n", foodLogs[i].times_eaten);
                printf("    Date First Tried: %-10.10s\n", foodLogs[i].date_first_tried);
                printf("    Location: %-30.30s\n", foodLogs[i].location_first_tried);
                printf("    Description:\n ");

                wrapFoodText(foodLogs[i].description, 8);  // Indented word wrap

                printf("------------------------------------------------------------\n");
            }
        }
    }
}

void wrapFoodText(const char *text, int indent)
{
    int len = strlen(text);
    int start = 0;

    // Trim leading spaces
    while (isspace(text[start])) start++;

    while (start < len)
    {
        int end = start + 52;
        if (end >= len)
        {
            printf("%*s%s\n", indent, "", &text[start]);  // No extra space added
            break;
        }

        while (end > start && !isspace(text[end]))  // Avoid breaking words
            end--;

        if (end == start)  // No space found, force break
            end = start + 52;

        printf("%*s%.*s\n", indent, "", end - start, &text[start]);
        start = end + 1;

        // Skip extra spaces after line break
        while (isspace(text[start])) start++;
    }
}

// Function to display the current food log details in the same format as `displayAllFoodLogs`
void displayFoodLogDetails(FoodLog *log)
{
    printf("\n------------------------------------------------------------\n");
    printf("                        FOOD LOG DETAILS                     \n");
    printf("------------------------------------------------------------\n");

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
            break;
    }

    printf("    Food Name: %-58.58s\n", log->food_name);
    printf("    Type: %s\n", foodTypeFull);
    printf("    Times Eaten: %-3d\n", log->times_eaten);
    printf("    Date First Tried: %-10.10s\n", log->date_first_tried);
    printf("    Location: %-30.30s\n", log->location_first_tried);
    printf("    Description:\n ");

    wrapFoodText(log->description, 8);  // Indented word wrap

    printf("------------------------------------------------------------\n");
}
int findFoodLogIndex(FoodLog food_log[], int count, char search_name[])
{
    int index = -1;  // Default to -1 (not found)

    for (int i = 0; i < count; i++)
    {
        if (strcmp(food_log[i].food_name, search_name) == 0)
        {
            index = i;  // Store the found index
        }
    }
    return index;  // Always return once at the end
}

void modifyFoodLog(FoodLog food_log[], int *count)
{
    char search_name[MAX_FOOD_NAME_LEN];
    int foundIndex = -1, isDuplicate = 0;
    char confirm;

    printf("\nModify Food Log\n");
    printf("Enter the food name to search for: ");
    scanf(" %[^\n]", search_name);  // Allow spaces in input

    foundIndex = findFoodLogIndex(food_log, *count, search_name);

    if (foundIndex == -1)
    {
        printf("\nError: Food log not found.\n");
    }
    else
    {
        // Display the current food log details
        displayFoodLogDetails(&food_log[foundIndex]);

        // Create a temporary structure to hold modifications
        FoodLog temp_log = food_log[foundIndex];

        printf("\nEnter new details:\n");
        getFoodName(&temp_log);
        getFoodType(&temp_log);
        getTimesEaten(&temp_log);
        getDateFirstTried(&temp_log);
        getLocationFirstTried(&temp_log);
        getFoodDescription(&temp_log);

        // Check for duplicate food name
        isFoodLogDuplicate(food_log, *count, temp_log.food_name, &isDuplicate);

        if (isDuplicate)
        {
            printf("\nError: Duplicate food name not allowed. Modification aborted.\n");
        }
        else
        {
            // Display the proposed changes for confirmation
            printf("\nProposed Changes:\n");
            displayFoodLogDetails(&temp_log);

            // Prompt for confirmation in a loop until valid input ('y' or 'n') is entered
            char confirm;
            int validInput = 0;
            do
            {
                printf("\nDo you want to apply these changes? (y/n): ");
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
                // Replace the original food log with the modified one
                food_log[foundIndex] = temp_log;
                printf("\nFood log updated successfully!\n");
            }
            else
            {
                printf("\nModification canceled. No changes were made.\n");
            }
        }
    }
}
void deleteFoodLog(FoodLog food_log[], int *count)
{
    char search_name[MAX_FOOD_NAME_LEN];
    int foundIndex = -1;
    char confirm;

    printf("\nDelete Food Log\n");
    printf("Enter the food name to search for: ");
    scanf(" %[^\n]", search_name);  // Allow spaces in input

    foundIndex = findFoodLogIndex(food_log, *count, search_name);

    if (foundIndex == -1)
    {
        printf("\nError: Food log not found.\n");
    }
    else
    {
        // Display the current food log details
        displayFoodLogDetails(&food_log[foundIndex]);

        // Ask for confirmation in a loop until valid input ('y' or 'n') is entered
        char confirm;
        int validInput = 0;
        do
        {
            printf("\nDo you want to delete this food log? (y/n): ");
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
            // Shift all subsequent food logs to remove the entry
            for (int i = foundIndex; i < *count - 1; i++)
            {
                food_log[i] = food_log[i + 1];
            }

            (*count)--;  // Decrement the food log count
            printf("\nFood log deleted successfully!\n");
        }
        else
        {
            printf("\nDeletion canceled. No changes were made.\n");
        }
    }
}

void searchFoodLog(FoodLog food_log[], int count)
{
    char search_name[MAX_FOOD_NAME_LEN];
    int foundIndex = 1;

    printf("\nSearch Food Log\n");
    printf("Enter the food name to search for: ");
    scanf(" %[^\n]", search_name);  // Allow spaces in input

    foundIndex = findFoodLogIndex(food_log, count, search_name);

    if (foundIndex != -1)
    {
        printf("\nFood Log Found:\n");
        displayFoodLogDetails(&food_log[foundIndex]);
    }
    else
    {
        printf("\nNo such food has been logged.\n");
    }

    printf("\nPress Enter to continue...");
    while (getchar() != '\n');  // Clear input buffer
    getchar();                  // Wait for user input before returning
}
