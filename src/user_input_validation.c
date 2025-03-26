#include "user_input_validation.h"

#include <ctype.h>
#include <stdio.h>
#include <string.h>

int validateUsername(const char *username)
{
    // Get username length
    int username_len;
    username_len = strlen(username);

    // Validation flag
    int isValid;
    isValid = 1;

    // Check if username is between 8 and 50 characters
    if (username_len < 8 || username_len > 50)
    {
        isValid = 0;
        printf("Username should be between 8 and 50 characters.\n");
    }

    // Check if username contains only alphanumeric characters
    for (int i = 0; i < username_len; i++)
    {
        if (!isalnum(username[i]))
        {
            printf("Username should only contain alphanumeric characters.\n");
            isValid = 0;
        }
    }
    return isValid;
}

int validatePassword(const char *password)
{
    // Get password length
    int password_len;
    password_len = strlen(password);

    // Validation flag
    int isValid;
    isValid = 1;

    // Check if password is between 8 and 20 characters
    if (password_len < 8 || password_len > 20)
    {
        isValid = 0;
        printf("Password should be between 8 and 20 characters.\n");
    }

    // Check if password contains at least one uppercase letter, one lowercase letter, one digit,
    // and one special character
    int has_upper = 0;
    int has_lower = 0;
    int has_digit = 0;
    int has_special = 0;
    const char special_characters[] = "!@#$%&*.";

    for (int i = 0; i < password_len; i++)
    {
        if (isupper(password[i]))
        {
            has_upper = 1;
        }
        if (islower(password[i]))
        {
            has_lower = 1;
        }
        if (isdigit(password[i]))
        {
            has_digit = 1;
        }
        if (strchr(special_characters, password[i]))
        {
            has_special = 1;
        }
    }

    if (!has_upper)
    {
        isValid = 0;
        printf("Password should contain at least one uppercase letter.\n");
    }

    if (!has_lower)
    {
        isValid = 0;
        printf("Password should contain at least one lowercase letter.\n");
    }

    if (!has_digit)
    {
        isValid = 0;
        printf("Password should contain at least one digit.\n");
    }

    if (!has_special)
    {
        isValid = 0;
        printf(
            "Password should contain at least one special character (!, @, #, $, %%, &, *, .).\n");
    }

    return isValid;
}

int validateFullName(const char *full_name)
{
    // Get full name length
    int full_name_len;
    full_name_len = strlen(full_name);

    // Validation flag
    int isValid;
    isValid = 1;

    // Check if full name is between 5 and 80 characters
    if (full_name_len < 5 || full_name_len > 80)
    {
        isValid = 0;
        printf("Full name should be between 5 and 80 characters.\n");
    }

    // Check if full name contains only alphabetic characters and spaces
    for (int i = 0; i < full_name_len; i++)
    {
        if (!isalpha(full_name[i]) && full_name[i] != ' ')
        {
            printf("Full name should only contain alphabetic characters and spaces.\n");
            isValid = 0;
        }
    }

    return isValid;
}

#include <ctype.h>
#include <stdio.h>
#include <string.h>

int validateEmail(const char *email)
{
    // Get email length
    int email_len = strlen(email);
    int isValid = 1;

    // Check if email is between 5 and 30 characters
    if (email_len < 5 || email_len > 30)
    {
        isValid = 0;
        printf("Email should be between 5 and 30 characters.\n");
    }

    // Ensure email starts with an alphabet
    if (!isalpha(email[0]))
    {
        isValid = 0;
        printf("Email should start with an alphabet.\n");
    }

    // Check for '@' and '.' with proper placement
    int at_index = -1, dot_index = -1;

    for (int i = 0; i < email_len; i++)
    {
        if (email[i] == '@')
        {
            at_index = i;
        }
        else if (email[i] == '.')
        {
            dot_index = i;
        }
    }

    // Conditions to check for valid email format
    if (at_index == -1 || dot_index == -1)
    {
        isValid = 0;
        printf("Email should contain '@' and '.' in the correct order.\n");
    }
    else if (at_index > dot_index)  // '@' should come before '.'
    {
        isValid = 0;
        printf("Email should have '@' before '.'.\n");
    }
    else if (dot_index - at_index < 2)  // At least one character between '@' and '.'
    {
        isValid = 0;
        printf("Email should have at least one character between '@' and '.'.\n");
    }
    else if (dot_index == email_len - 1)  // '.' should not be at the end
    {
        isValid = 0;
        printf("Email should not end with '.'.\n");
    }

    return isValid;
}

int validateMobileNumber(const char *mobile_number)
{
    // Get mobile number length
    int mobile_number_len;
    mobile_number_len = strlen(mobile_number);

    // Validation flag
    int isValid;
    isValid = 1;

    // Check if mobile number is exactly 11 characters and starts with '0'
    if (mobile_number_len != 11 || mobile_number[0] != '0')
    {
        isValid = 0;
        printf("Mobile number should be exactly 11 digits and start with '0'.\n");
    }

    // Check if mobile number contains only digits
    for (int i = 0; i < mobile_number_len; i++)
    {
        if (!isdigit(mobile_number[i]))
        {
            printf("Mobile number should contain only digits.\n");
            isValid = 0;
        }
    }
    return isValid;
}