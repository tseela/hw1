#include "ErrorCode.h"
#include <stdio.h>
#include <string.h>


bool error_isSuccess(const ErrorCode code) {
    return code == ERROR_SUCCESS;
}

const char* error_getErrorMessage(const ErrorCode code) {
    if (code == ERROR_SUCCESS) {
        return "There wasn't any error. Good job!";
    }
    if (code == ERROR_MEMORY) {
        return "ERROR! Not enough memory in the device.";
    }
    if (code == ERROR_NULL_PTR) {
        return "ERROR! Null expression was found. Can't recieve any data from a \"null variable\".";
    }
    if (code == ERROR_OUT_OF_RANGE) {
        return "ERROR! Requested row or col does not exists in the given matrix.";
    }
    if (code == ERROR_SIZES) {
        return "ERROR! Matrices's sizes do not match.";
    }
    if (code == ERROR_ZERO_SIZE) {
        return "ERROR! The width and height of the matrix can't be 0.";
    }
    return "ERROR! An undefined error occured.";
}
