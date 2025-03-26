#include "user.h"

#include <stdio.h>
#include <string.h>

#include "data_structures.h"
#include "food_log.h"
#include "recipe.h"
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

    if (valid == 0)
    {
        printf("\nToo many failed attempts. Please try logging in again later.\n");
        printf("Press any key to exit...\n");
        getchar();  // Wait for user input
    }
}

void displayUser(UserCredentials *user)
{
    printf("\n------------------------------------------------------------\n");
    printf("                        USER DETAILS                         \n");
    printf("------------------------------------------------------------\n");

    printf("    Full Name:     %-58.58s\n", user->full_name);
    printf("    Username:      %-30.30s\n", user->username);
    printf("    Email:         %-40.40s\n", user->email);
    printf("    Mobile Number: %-15.15s\n", user->mobile_number);

    printf("------------------------------------------------------------\n");
}

void displayUserFoodLogsAndRecipes(FoodLog food_log[], int food_count, Recipe recipe_list[],
                                   int recipe_count, UserCredentials *logged_in_user)
{
    char search_username[MAX_USERNAME_LEN];
    int found_in_food_log = 0, found_in_recipe = 0;
    int i;
    FoodLog filtered_food_logs[MAX_FOOD_LOG];
    Recipe filtered_recipes[MAX_RECIPE];
    int filtered_food_count = 0, filtered_recipe_count = 0;
    char full_name[MAX_FULL_NAME_LEN] = "Unknown User";
    int full_name_set = 0;

    // Get username input
    printf("\nEnter the username to search: ");
    scanf("%s", search_username);

    // Search for user in food logs
    i = 0;
    while (i < food_count)
    {
        if (strcmp(food_log[i].username, search_username) == 0)
        {
            found_in_food_log = 1;
            if (!full_name_set)
            {
                strcpy(full_name, food_log[i].full_name);  // Assume this field exists
                full_name_set = 1;
            }
            filtered_food_logs[filtered_food_count] = food_log[i];
            filtered_food_count++;
        }
        i++;
    }

    // Search for user in recipes
    i = 0;
    while (i < recipe_count)
    {
        if (strcmp(recipe_list[i].username, search_username) == 0)
        {
            found_in_recipe = 1;
            if (!full_name_set)
            {
                strcpy(full_name, recipe_list[i].full_name);  // Assume this field exists
                full_name_set = 1;
            }
            filtered_recipes[filtered_recipe_count] = recipe_list[i];
            filtered_recipe_count++;
        }
        i++;
    }

    // If user not found in food logs or recipes, display an error
    if (!found_in_food_log && !found_in_recipe)
    {
        printf("\nError: User '%s' not found in records.\n", search_username);
    }
    else
    {
        // If searched user is logged-in user, show additional details
        if (strcmp(search_username, logged_in_user->username) == 0)
        {
            printf("\nDisplaying full user details...\n");
            displayUser(logged_in_user);
        }

        else
        {
            // Display user information
            printf("\n------------------------------------------------------------\n");
            printf("                        USER DETAILS                         \n");
            printf("------------------------------------------------------------\n");
            printf("    Full Name: %-58.58s\n", full_name);
            printf("    Username:  %-30.30s\n", search_username);
            printf("------------------------------------------------------------\n");
        }

        // Display Food Logs
        if (filtered_food_count > 0)
        {
            displayAllFoodLogs(filtered_food_logs, filtered_food_count);
        }
        else
        {
            printf("No food logs found for this user.\n");
        }

        // Display Recipes
        if (filtered_recipe_count > 0)
        {
            displayAllRecipes(filtered_recipes, filtered_recipe_count);
        }
        else
        {
            printf("No recipes found for this user.\n");
        }
    }
}
