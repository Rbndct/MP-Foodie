#ifndef DATA_STRUCTURES_H
#define DATA_STRUCTURES_H

// Maximum lengths for user data
#define MAX_USERNAME_LEN 51    // 50 characters + 1 for the null terminator
#define MAX_PASSWORD_LEN 21    // 20 characters + 1 for the null terminator
#define MAX_FULL_NAME_LEN 81   // 80 characters + 1 for the null terminator
#define MAX_EMAIL_LEN 31       // 30 characters + 1 for the null terminator
#define MAX_MOBILE_NUM_LEN 12  // 11 characters + 1 for the null terminator

// Maximum lengths for food log data
#define MAX_FOOD_NAME 51
#define MAX_DATE_FIRST_TRIED 11
#define MAX_LOCATION_FIRST_TRIED 31
#define MAX_DESCRIPTION 301

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
    char food_name[MAX_FOOD_NAME];
    char food_type;
    int times_eaten;
    char date_first_tried[MAX_DATE_FIRST_TRIED];
    char location_first_tried[MAX_LOCATION_FIRST_TRIED];
    char description[MAX_DESCRIPTION];
} FoodLog;

#endif  // DATA_STRUCTURES_H