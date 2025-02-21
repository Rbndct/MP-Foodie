#include "input_validation.h"

#include <ctype.h>
#include <stdio.h>
#include <string.h>

int validateUsername(const char *username)
{
    // Get username length
    int username_len = strlen(username);
    int isValid = 1;

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
    int password_len = strlen(password);
    int isValid = 1;

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
    int full_name_len = strlen(full_name);
    int isValid = 1;

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

    if (!isalpha(email[0]))
    {
        isValid = 0;
        printf("Email should start with an alphabet.\n");
    }

    // Check if email contains '@' and '.'
    int has_at = -1;
    int has_dot = -1;

    for (int i = 0; i < email_len; i++)
    {
        if (email[i] == '@')
        {
            has_at = i;
        }
        else if (email[i] == '.')
        {
            has_dot = i;
        }
    }

    if (has_at == -1 || has_dot == -1 || has_at > has_dot)
    {
        isValid = 0;
        printf("Email should contain '@' and '.' in the correct order.\n");
    }

    return isValid;
}

int validateMobileNumber(const char *mobile_number)
{
    int mobile_number_len = strlen(mobile_number);
    int isValid = 1;

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