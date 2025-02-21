#ifndef INPUT_VALIDATION_H
#define INPUT_VALIDATION_H

#include <stdbool.h>

#include "data_structures.h"

int validateUsername(const char *);
int validatePassword(const char *);
int validateFullName(const char *);
int validateEmail(const char *);
int validateMobileNumber(const char *);

#endif  // INPUT_VALIDATION_H