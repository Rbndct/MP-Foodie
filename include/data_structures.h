#ifndef DATA_STRUCTURES_H
#define DATA_STRUCTURES_H

// Maximum lengths for user data
#define MAX_USERS 5  // Maximum users that can be stored

#define MAX_USERNAME_LEN 51    // 50 characters + 1 for the null terminator
#define MAX_PASSWORD_LEN 21    // 20 characters + 1 for the null terminator
#define MAX_FULL_NAME_LEN 81   // 80 characters + 1 for the null terminator
#define MAX_EMAIL_LEN 31       // 30 characters + 1 for the null terminator
#define MAX_MOBILE_NUM_LEN 12  // 11 characters + 1 for the null terminator

// Maximum lengths for food log data
#define MAX_FOOD_LOG 50
#define MAX_FOOD_NAME_LEN 51         // 50 characters + 1 for the null terminator
#define MAX_DATE_FIRST_TRIED_LEN 11  // Format mm/dd/yyyy (10 chars +  1 for the null terminator)
#define MAX_LOCATION_FIRST_TRIED_LEN 31  // Allows 30 characters + 1 for the null terminator
#define MAX_DESCRIPTION_LEN 301          // Allows 300 characters + 1 for the null terminator

// Maximum lengths for recipe data
#define MAX_RECIPE 20               // Maximum number of recipes records
#define MAX_RECIPE_INGREDIENTS 20   // Maximum number of ingredients in a recipe
#define MAX_RECIPE_INSTRUCTIONS 20  // Maximum number of instructions in a recipe

#define MAX_RECIPE_NAME_LEN 51          // 50 chars + 1 for  null terminator
#define MAX_RECIPE_DESCRIPTION_LEN 161  // 160 chars + 1 for null terminator
#define MAX_INGREDIENT_LEN 81           // 80 chars + 1 for null terminator
#define MAX_INSTRUCTION_LEN 101         // 100 chars + 1 for null terminator

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
    char username[MAX_USERNAME_LEN];                          // Username field
    char full_name[MAX_FULL_NAME_LEN];                        // Full name field
    char food_name[MAX_FOOD_NAME_LEN];                        // Food name field
    char food_type;                                           // Food type field
    int times_eaten;                                          // Times eaten field
    char date_first_tried[MAX_DATE_FIRST_TRIED_LEN];          // Date first tried field
    char location_first_tried[MAX_LOCATION_FIRST_TRIED_LEN];  // Location first tried field
    char description[MAX_DESCRIPTION_LEN];                    // Description field
} FoodLog;

typedef struct
{
    char username[MAX_USERNAME_LEN];                               // Username field
    char full_name[MAX_FULL_NAME_LEN];                             // Full name field
    char recipe_name[MAX_RECIPE_NAME_LEN];                         // Recipe name field
    char recipe_description[MAX_RECIPE_DESCRIPTION_LEN];           // Recipe description field
    int time_to_prepare;                                           // Time to prepare field
    int time_to_cook;                                              // Time to cook field
    int num_of_ingredients;                                        // Number of ingredients field
    char ingredients[MAX_RECIPE_INGREDIENTS][MAX_INGREDIENT_LEN];  // Ingredients field
    int num_of_instructions;                                       // Number of instructions field
    char instructions[MAX_RECIPE_INSTRUCTIONS][MAX_INSTRUCTION_LEN];  // Instructions field
} Recipe;

#endif  // DATA_STRUCTURES_H