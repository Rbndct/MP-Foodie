#include "food_validation.h"

#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#include "data_structures.h"

int validateFoodName(char *food_name)
{
    int isValid = 1;  // Assume valid unless proven otherwise
    int foodName_len = strlen(food_name);

    // Check if food name is between 3 and 50 characters
    if (foodName_len < 3 || foodName_len > MAX_FOOD_NAME_LEN - 1)
    {
        printf("Food name should be between 3 and 50 characters.\n");
        isValid = 0;
    }

    // Check if food name contains only alphanumeric characters and spaces
    for (int i = 0; i < foodName_len; i++)
    {
        if (!isalnum(food_name[i]) && food_name[i] != ' ')
        {
            printf("Food name should only contain alphanumeric characters.\n");
            isValid = 0;
            break;  // No need to check further if already invalid
        }
    }

    // Clear excess input from buffer if input was too long
    int ch, overflow = 0;
    while ((ch = getchar()) != '\n' && ch != EOF)
    {
        overflow = 1;
    }

    if (overflow)
    {
        printf("Input was too long! Only 50 characters allowed.\n");
        food_name[0] = '\0';  // Reset invalid input
        isValid = 0;
    }

    return isValid;
}

int validateFoodType(char food_type)
{
    const char foodTypes[] = { 'a', 'm', 'd' };
    int i = 0;
    int isValid = 0;

    while (i < 3 && !isValid)
    {
        isValid = (food_type == foodTypes[i]);
        i++;
    }

    if (!isValid)
    {
        printf(
            "Invalid food type. Please enter 'a' (Appetizer), 'm' (Main Course), or 'd' "
            "(Dessert).\n");
    }

    return isValid;
}

int validateTimesEaten(const int *timesEaten)
{
    int isValid = 1;

    // Check if it is a positive integer
    if (*timesEaten <= 0)
    {
        isValid = 0;
        printf("Times eaten must be a positive integer.\n");
    }

    return isValid;
}

int validateDateFirstTried(const char *dateFirstTried)
{
    // Array of months in a year
    const char *months[12] = {
        "January", "February", "March",     "April",   "May",      "June",
        "July",    "August",   "September", "October", "November", "December"
    };
    // Array of days in each month
    int daysInMonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    // Get date length
    int date_len;
    date_len = strlen(dateFirstTried);

    // Validation flag
    int isValid;
    isValid = 1;

    // Get the current year
    int currentYear;
    currentYear = getCurrentYear();

    // Check if date is in the format MM/DD/YYYY
    if (date_len != 10 && (dateFirstTried[2] != '/' || dateFirstTried[5] != '/'))
    {
        isValid = 0;
        printf("Date should be in the format MM/DD/YYYY.\n");
    }
    else
    {
        int month, day, year;
        if (sscanf(dateFirstTried, "%2d/%2d/%4d", &month, &day, &year) != 3)
        {
            isValid = 0;
            printf("Date should be in the format MM-DD-YYYY.\n");
        }
        else
        {
            // Adjust February for leap years
            if (month == 2 && isLeapYear(year))
            {
                daysInMonth[1] = 29;
            }

            // Check if month is between 1 and 12
            if (month < 1 || month > 12)
            {
                isValid = 0;
                printf("Month should be between 1 and 12.\n");
            }

            // Check if day is between 1 and 31
            if (day < 1 || day > 31)
            {
                isValid = 0;
                printf("Day should be between 1 and 31.\n");
            }

            if (day < 0 || day > daysInMonth[month - 1])
            {
                isValid = 0;
                printf("Invalid day for the month of %s.\n", months[month - 1]);
            }

            if (year < 1970 || year > currentYear)
            {
                isValid = 0;
                printf("Year should be between 1970 and %d.\n", currentYear);
            }
        }
    }
    return isValid;
}

int isLeapYear(int year)
{
    int leap = 0;  // Default to not a leap year

    if (year % 4 == 0)
    {
        if (year % 100 != 0 || year % 400 == 0)
        {
            leap = 1;  // is a leap year
        }
    }
    return leap;
}

int getCurrentYear()
{
    time_t now;
    time(&now);                          // Get the current time
    struct tm *local = localtime(&now);  // Get the local time
    return local->tm_year + 1900;        // Extract the current year
}

int validateLocationFirstTried(char *locationFirstTried)
{
    int isValid = 1;  // Assume valid unless proven otherwise
    int location_len = strlen(locationFirstTried);

    // Check if location is between 1 and 30 characters
    if (location_len < 1 || location_len > MAX_LOCATION_FIRST_TRIED_LEN - 1)
    {
        printf("Location should be between 1 and 30 characters.\n");
        isValid = 0;
    }

    // Clear excess input from buffer if input was too long
    int ch, overflow = 0;
    while ((ch = getchar()) != '\n' && ch != EOF)
    {
        overflow = 1;
    }

    if (overflow)
    {
        printf("Input was too long! Only 30 characters allowed.\n");
        locationFirstTried[0] = '\0';  // Reset invalid input
        isValid = 0;
    }

    return isValid;
}

int validateFoodDescription(char *description)
{
    int isValid = 1;  // Assume valid unless proven otherwise

    // Check description length
    int length = strlen(description);
    if (length == 0 || length > MAX_DESCRIPTION_LEN)
    {
        isValid = 0;
        printf("Description should be between 1 and 300 characters.\n");
    }

    // Clear excess input from buffer if input was too long
    int ch, overflow = 0;
    while ((ch = getchar()) != '\n' && ch != EOF)
    {
        overflow = 1;  // Mark that input was too long
    }

    if (overflow)
    {
        isValid = 0;
        printf("Input was too long! Only 300 characters allowed.\n");
        description[0] = '\0';  // Reset invalid input
    }

    return isValid;
}
