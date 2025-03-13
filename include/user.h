#ifndef USER_H
#define USER_H

#include "data_structures.h"

// Function prototypes for user account management
void registerUser(UserCredentials *);
void loginToUserAccount(UserCredentials *);

// Function declarations for user input
void getUsername(UserCredentials *);
void getPassword(UserCredentials *);
void getFullName(UserCredentials *);
void getMobileNumber(UserCredentials *);
void getEmail(UserCredentials *);

#endif  // USER_H