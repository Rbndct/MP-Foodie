#ifndef USER_INPUT_VALIDATION_H
#define USER_INPUT_VALIDATION_H

#include <stdbool.h>

#include "data_structures.h"

int validateUsername(const char *);
int validatePassword(const char *);
int validateFullName(const char *);
int validateEmail(const char *);
int validateMobileNumber(const char *);

#endif  // USER_INPUT_VALIDATION_H