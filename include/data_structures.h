#ifndef DATA_STRUCTURES_H
#define DATA_STRUCTURES_H

// Maximum lengths for user data
#define MAX_USERNAME_LEN 51    // 50 characters + 1 for the null terminator
#define MAX_PASSWORD_LEN 21    // 20 characters + 1 for the null terminator
#define MAX_FULL_NAME_LEN 81   // 80 characters + 1 for the null terminator
#define MAX_EMAIL_LEN 31       // 30 characters + 1 for the null terminator
#define MAX_MOBILE_NUM_LEN 12  // 11 characters + 1 for the null terminator

// Maximum lengths for food log data
#define MAX_FOOD_NAME_LEN 51
#define MAX_DATE_FIRST_TRIED_LEN 11
#define MAX_LOCATION_FIRST_TRIED_LEN 31
#define MAX_DESCRIPTION_LEN 301

// Maximum lengths for recipe data
#define MAX_RECIPE 20
#define MAX_RECIPE_INGREDIENTS 20
#define MAX_RECIPE_INSTRUCTIONS 20

#define MAX_RECIPE_NAM_LEN 51
#define MAX_RECIPE_DESCRIPTION_LEN 161
#define MAX_INGREDIENT_LEN 81
#define MAX_INSTRUCTION_LEN 101

// Define the UserCredentials structure
typedef struct
{
    char username[MAX_USERNAME_LEN];         // Username field
    char password[MAX_PASSWORD_LEN];         // Password field
    char full_name[MAX_FULL_NAME_LEN];       // Full name field
    char email[MAX_EMAIL_LEN];               // Email field
    char mobile_number[MAX_MOBILE_NUM_LEN];  // Phone field
} UserCredentials;

typedef struct
{
    char food_name[MAX_FOOD_NAME_LEN];
    char food_type;
    int times_eaten;
    char date_first_tried[MAX_DATE_FIRST_TRIED_LEN];
    char location_first_tried[MAX_LOCATION_FIRST_TRIED_LEN];
    char description[MAX_DESCRIPTION_LEN];
} FoodLog;

typedef struct
{
    char recipe_name[MAX_FOOD_NAME_LEN];
    char recipe_description[MAX_DESCRIPTION_LEN];
    int time_to_prepare;
    int time_to_cook;
    int num_of_ingredients;
    char ingredients[MAX_RECIPE_INGREDIENTS][MAX_INGREDIENT_LEN];
    int num_of_instructions;
    char instructions[MAX_RECIPE_INSTRUCTIONS][MAX_INSTRUCTION_LEN];
} Recipe;

#endif  // DATA_STRUCTURES_H