#include "food_validation.h"

#include <_ctype.h>
#include <stdio.h>
#include <string.h>

int validateFoodName(const char *food_name)
{
    // Get food name length
    int foodName_len = strlen(food_name);
    int isValid = 1;

    // Check if food name is between 3 and 50 characters
    if (foodName_len < 3 || foodName_len > 50)
    {
        isValid = 0;
        printf("Food name should be between 3 and 50 characters.\n");
    }

    // Check if food name contains only alphanumeric characters
    for (int i = 0; i < foodName_len; i++)
    {
        if (!isalnum(food_name[i]))
        {
            printf("Food name should only contain alphanumeric characters.\n");
            isValid = 0;
        }
    }
    return isValid;
}

int validateFoodType(const char *food_type)
{
    /*
    Food types: a- appetizer, m- main course, d- dessert,
    */
    char foodTypes[] = {'a', 'm', 'd'};
    int isValid = 1;

    // Check if food type is in foodTypes array
    if (strchr(foodTypes, food_type[0]) == NULL)
    {
        isValid = 0;
        printf("Invalid food type.\n");
    }
    return isValid;
}

int validateTimesEaten(const int *timesEaten)
{
    int isValid = 1;

    // Check if it is a positive integer
    if (timesEaten < 0)
    {
        isValid = 0;
        printf("Times eaten should be a positive integer.\n");
    }
    return isValid;
}

int validateDateFirstTried(const char *dateFirstTried)
{
    char months[][12] = {"January", "February", "March",     "April",   " May",     "June",
                         "July",    "August",   "September", "October", "November", "December"};
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    // Get date length
    int date_len = strlen(dateFirstTried);
    int isValid = 1;

    // Check if date is in the format MM/DD/YYYY
    if (date_len != 10 && (dateFirstTried[2] != '/' || dateFirstTried[5] != '/'))
    {
        isValid = 0;
        printf("Date should be in the format YYYY-MM-DD.\n");
    }
    else
    {
        int month, day, year;
        if (sscanf(dateFirstTried, "%2d/%2d/%4d", &month, &day, &year) != 3)
        {
            isValid = 0;
            printf("Date should be in the format YYYY-MM-DD.\n");
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

            if (day < daysInMonth[month - 1])
            {
                isValid = 0;
                printf("Invalid day for the month of %s.\n", months[month - 1]);
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

int validateLocationFirstTried(const char *locationFirstTried)
{
    // Get location length
    int location_len = strlen(locationFirstTried);
    int isValid = 1;

    // Check if location is between 0 and 30 characters
    if (location_len < 0 || location_len > 30)
    {
        isValid = 0;
        printf("Location should be between 3 and 30 characters.\n");
    }

    return isValid;
}

int validateDescription(const char *description)
{
    // Get description length
    int description_len = strlen(description);
    int isValid = 1;

    // Check if description is between 0 and 300 characters
    if (description_len < 0 || description_len > 300)
    {
        isValid = 0;
        printf("Description should be between 0 and 300 characters.\n");
    }

    return isValid;
}