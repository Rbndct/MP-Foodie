// Author: Raphael Maagma
// Date: '24
#include <stdio.h>
#include <string.h>

#include "input_validation.c"
#include "user.c"

int main()
{
    UserCredentials user;
    getUsername(&user);
    getPassword(&user);
    getFullName(&user);
    getEmail(&user);
    getMobileNumber(&user);

    // Testing
    printf("\n\nUser credentials:\n");
    printf("Username: %s\n", user.username);
    printf("Password: %s\n", user.password);
    printf("Full name: %s\n", user.full_name);
    printf("Email: %s\n", user.email);
    printf("Mobile number: %s\n", user.mobile_number);

    return 0;
}