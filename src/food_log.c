#include "food_log.h"

#include <stdio.h>

#include "data_structures.h"
#include "food_validation.h"

/**
 * @brief Adds a new food log entry.
 *
 * This function prompts the user to enter details for a new food log entry
 * and validates each input.
 *
 * @param food_log Pointer to the FoodLog structure to be filled.
 */
void addFoodLog(FoodLog *food_log)
{
    printf("\nAdd Food Log\n");
    getFoodName(food_log);
    getFoodType(food_log);
    getTimesEaten(food_log);
    getDateFirstTried(food_log);
    getLocationFirstTried(food_log);
    getFoodDescription(food_log);
}

/**
 * @brief Prompts the user to enter the food name and validates it.
 *
 * This function repeatedly prompts the user to enter a valid food name
 * until a valid input is provided.
 *
 * @param food_log Pointer to the FoodLog structure to store the food name.
 */
void getFoodName(FoodLog *food_log)
{
    do
    {
        printf("\nEnter food name: ");
        scanf("%50[^\n]", food_log->food_name);
        while (getchar() != '\n');  // Clear the input buffer
    } while (!validateFoodName(food_log->food_name));
}

/**
 * @brief Prompts the user to enter the food type and validates it.
 *
 * This function repeatedly prompts the user to enter a valid food type
 * until a valid input is provided.
 *
 * @param food_log Pointer to the FoodLog structure to store the food type.
 */
void getFoodType(FoodLog *food_log)
{
    do
    {
        printf("\nEnter food type: ");
        printf("a- appetizer, m- main course, d- dessert\n");
        scanf("%c", &food_log->food_type);  // Note the space before %c to skip any whitespace
        while (getchar() != '\n');          // Clear the input buffer
    } while (!validateFoodType(&food_log->food_type));
}

void getTimesEaten(FoodLog *food_log)
{
    do
    {
        printf("\nEnter times eaten: ");
        scanf("%d", &food_log->times_eaten);
        while (getchar() != '\n');
    } while (!validateTimesEaten(&food_log->times_eaten));
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