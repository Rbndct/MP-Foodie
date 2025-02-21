#ifndef DATA_STRUCTURES_H
#define DATA_STRUCTURES_H

// Maximum lengths for user data
#define MAX_USERNAME_LEN 51    // 50 characters + 1 for the null terminator
#define MAX_PASSWORD_LEN 21    // 20 characters + 1 for the null terminator
#define MAX_FULL_NAME_LEN 81   // 80 characters + 1 for the null terminator
#define MAX_EMAIL_LEN 31       // 30 characters + 1 for the null terminator
#define MAX_MOBILE_NUM_LEN 12  // 11 characters + 1 for the null terminator

// Define the UserCredentials structure
typedef struct
{
    char username[MAX_USERNAME_LEN];         // Username field
    char password[MAX_PASSWORD_LEN];         // Password field
    char full_name[MAX_FULL_NAME_LEN];       // Full name field
    char email[MAX_EMAIL_LEN];               // Email field
    char mobile_number[MAX_MOBILE_NUM_LEN];  // Phone field
} UserCredentials;

#endif  // DATA_STRUCTURES_H