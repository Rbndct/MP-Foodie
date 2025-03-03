#include "user.h"

#include <stdio.h>
#include <string.h>

#include "data_structures.h"
#include "user_input_validation.h"

void getUsername(UserCredentials *user)
{
    do
    {
        printf("\nEnter username: ");
        scanf("%50s", user->username);  // Use %50s to limit input to 50 characters
        while (getchar() != '\n');      // Clear the input buffer
    } while (!validateUsername(user->username));  // Call the validateUsername function
}

void getPassword(UserCredentials *user)
{
    int match = 0;
    char password[MAX_PASSWORD_LEN];          // Temporary password variable
    char confirm_password[MAX_PASSWORD_LEN];  // Temporary confirm password variable

    do
    {
        printf("\nEnter password: ");
        scanf("%20s", password);    // Use %20s to limit input to 20 characters
        while (getchar() != '\n');  // Clear the input buffer

        printf("Confirm password: ");
        scanf("%20s", confirm_password);  // Use %20s to limit input to 20 characters
        while (getchar() != '\n');        // Clear the input buffer

        // Check if password and confirm password match
        if (strcmp(password, confirm_password) == 0)
        {
            // Copy the password to the user structure if they match
            strcpy(user->password, password);
            match = 1;
        }
        // If the passwords do not match, display an error message
        else
        {
            printf("\nPasswords do not match. Please try again.\n");
        }
    } while (match == 0 ||
             !validatePassword(user->password));  // Call the validatePassword function
}

void getFullName(UserCredentials *user)
{
    do
    {
        printf("\nEnter full name: ");
        scanf("%80[^\n]", user->full_name);  // Use %80[^\n] to allow spaces in the input
        while (getchar() != '\n');           // Clear the input buffer
    } while (!validateFullName(user->full_name));  // Call the validateFullName function
}

void getEmail(UserCredentials *user)
{
    do
    {
        printf("\nEnter email: ");
        scanf("%30s", user->email);  // Use %30s to limit input to 30 characters
        while (getchar() != '\n');   // Clear the input buffer
    } while (!validateEmail(user->email));  // Call the validateEmail function
}

void getMobileNumber(UserCredentials *user)
{
    do
    {
        printf("\nEnter mobile number: ");
        scanf("%11s", user->mobile_number);  // Use %11s to limit input to 11 characters
        while (getchar() != '\n');           // Clear the input buffer
    } while (!validateMobileNumber(user->mobile_number));  // Call the validateMobileNumber function
}

void registerUser(UserCredentials *user)
{
    // Gets user input from username to mobile number
    printf("\nRegister an account\n");
    getUsername(user);
    getPassword(user);
    getFullName(user);
    getEmail(user);
    getMobileNumber(user);

    // Display success message
    printf("Successfully registered!\n");
}

void loginToUserAccount(UserCredentials *user)
{
    // Temporary input variable
    char temp_user[MAX_USERNAME_LEN];
    char temp_password[MAX_PASSWORD_LEN];

    // Variable for user attempts to login (Max of 3)
    int attempts = 3, valid = 0;
    do
    {
        printf("\nLogin to your account\n");

        // Get username and password
        printf("\nEnter username: ");
        scanf("%50s", temp_user);

        printf("Enter password: ");
        scanf("%20s", temp_password);
        // Check if username and password match
        if (strcmp(user->username, temp_user) == 0 && strcmp(user->password, temp_password) == 0)
        {
            // If they match, display success message and set valid to 1
            printf("\nSuccessfully logged in!\n");
            valid = 1;
        }
        else
        {
            // If they do not match, display error message and decrement attempts
            printf("\nInvalid username or password. Please try again.\n");
            attempts--;
            printf("Attempts left: %d\n", attempts);
        }
        // If attempts reach 0, display error message and exit loop
    } while (attempts > 0 && valid == 0);
}
