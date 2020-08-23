#pragma once

#include <stdbool.h>
#include <stdint.h>

typedef enum {
    // No error
    ERROR_SUCCESS = 0,
    // malloc faild
    ERROR_MEMORY = 1,
    // the user gave the function a NULL pointer
    ERROR_NULL_PTR = 2,
    // the user tries to approach a row or a col that doesn't exists
    ERROR_OUT_OF_RANGE = 3,
    // the user tries to add two matrixes from different sizes
    ERROR_MATRIX_SIZE = 4,
    // matrix's width or height can't be 0
    ERROR_ZERO_SIZE = 5
} ErrorCode;

/**
 * @brief Checks if a given error code indicates a success or not.
 *
 * @param[in] code the error code.
 * @return whether the error code indicates a success or not.
 */
bool error_isSuccess(ErrorCode code);

/**
 * @brief gets a textual error message for a given error code.
 *
 * @param[in] code the error code.
 * @return const char* the textual representation of the error code.
 */
const char* error_getErrorMessage(ErrorCode code);