#include "ErrorCode.h"
#include <stdio.h>
#include <string.h>


bool error_isSuccess(const ErrorCode code) {
    return code == ERROR_SUCCESS;
}

const char* error_getErrorMessage(const ErrorCode code) {
    // note that there are 6 error codes
    const char* const errorMessage[] = {"There wasn't any error. Good job!",
    "ERROR! Not enough memory in the device.",
    "ERROR! Null expression was found. Can't recieve any data from a \"null variable\".",
    "ERROR! Requested row or col does not exists in the given matrix.",
    "ERROR! Matrices's sizes do not match.",
    "ERROR! The width and height of the matrix can't be 0."};
    if (6 >= code && code >= 0) {
        return errorMessage[code];
    }
    return "ERROR! An undefined error occured.";
}
