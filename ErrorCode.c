#include "ErrorCode.h"
#include <stdio.h>

bool error_isSuccess(ErrorCode code) {
    if (code == ERROR_SUCCESS)
        return true;
    return false;
}

const char* error_getErrorMessage(ErrorCode code) {
    switch (code) {
        case ERROR_SUCCESS:
            char[] arr = "There wasn't any error. Good job!";
            break;
        case ERROR_MEMORY:
            return "ERROR! Not enough memory in the device.";
            break;
        case ERROR_SIZE:
            return "ERROR! The minimum size of the matrix is 1X1 (and not less!).";
            break;
        case ERROR_NULL:
            return "ERROR! Null expression was found. Can't recieve any data from a \"null matrix\"";
    }
}
