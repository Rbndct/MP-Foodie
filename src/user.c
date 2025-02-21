#include "user.h"

#include <stdio.h>
#include <string.h>

#include "data_structures.h"
#include "input_validation.h"

void getUsername(UserCredentials *user)
{
    do
    {
        printf("Enter username: ");
        scanf("%50s", user->username);  // Use %50s to limit input to 50 characters
        while (getchar() != '\n');      // Clear the input buffer
    } while (!validateUsername(user->username));  // Call the validateUsername function
}

void getPassword(UserCredentials *user)
{
    char password[MAX_PASSWORD_LEN];          // Temporary password variable
    char confirm_password[MAX_PASSWORD_LEN];  // Temporary confirm password variable
    do
    {
        // Input password
        printf("Enter password: ");
        scanf("%20s", password);    // Use %20s to limit input to 20 characters
        while (getchar() != '\n');  // Clear the input buffer

        // Input confirmation password
        printf("Confirm password: ");
        scanf("%20s", confirm_password);  // Use %20s to limit input to 20 characters
        while (getchar() != '\n');        // Clear the input buffer

        // Check if passwords match
        if (strcmp(password, confirm_password) != 0)
        {
            printf("Passwords do not match. Please try again.\n");
        }
    } while (!validatePassword(password));  // Ensure valid password
    strcpy(user->password, password);  // Copy password to user struct
}

void getFullName(UserCredentials *user)
{
    do
    {
        printf("Enter full name: ");
        scanf("%80[^\n]", user->full_name);  // Use %80[^\n] to allow spaces in the input
        while (getchar() != '\n');           // Clear the input buffer
    } while (!validateFullName(user->full_name));  // Call the validateFullName function
}

void getEmail(UserCredentials *user)
{
    do
    {
        printf("Enter email: ");
        scanf("%30s", user->email);  // Use %30s to limit input to 30 characters
        while (getchar() != '\n');   // Clear the input buffer
    } while (!validateEmail(user->email));  // Call the validateEmail function
}

void getMobileNumber(UserCredentials *user)
{
    do
    {
        printf("Enter mobile number: ");
        scanf("%11s", user->mobile_number);  // Use %11s to limit input to 11 characters
        while (getchar() != '\n');           // Clear the input buffer
    } while (!validateMobileNumber(user->mobile_number));  // Call the validateMobileNumber function
}