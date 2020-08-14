#include "ErrorCode.h"
#include <stdio.h>
#include <string.h>


bool error_isSuccess(ErrorCode code) {
    if (code == ERROR_SUCCESS)
        return true;
    return false;
}

const char* error_getErrorMessage(ErrorCode code) {
    switch (code) {
        case ERROR_SUCCESS:
            return "There wasn't any error. Good job!";
            break;
        case ERROR_MEMORY:
            return "ERROR! Not enough memory in the device.";
            break;
        case ERROR_NULL:
            return "ERROR! Null expression was found. Can't recieve any data from a \"null matrix\".";
            break;
        case ERROR_ROW_COL:
            return "ERROR! Requested row or col does not exists in the given matrix.";
            break;
        case ERROR_ADD_SIZES:
            return "ERROR! You can't add up matrices from different sizes.";
            break;
        case ERROR_MULT_SIZES:
            return "ERROR! Can't multiply the given matrices (sizes does not match).";
            break;
        case ERROR_ZERO_SIZE:
            return "ERROR! The width and height of the matrix can't be 0.";
            break;
        // in case someone will try to check an error code that we didn't difined we will return the folowing massage:
        default:
            return "ERROR! An undefined error occured.";
    }
}
