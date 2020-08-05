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
            char arr[] = "There wasn't any error. Good job!";
            break;
        case ERROR_MEMORY:
            char arr[] = "ERROR! Not enough memory in the device.";
            break;
        case ERROR_SIZE:
            char arr[] = "ERROR! The minimum size of the matrix is 1X1 (and not less!).";
            break;
        case ERROR_NULL:
            char arr[] = "ERROR! Null expression was found. Can't recieve any data from a \"null matrix\".";
            break;
        default:
            char arr[] = "ERROR! An undefined error occured.";
    }
    char* massage = (char*) malloc(sizeof(char) * strlen(arr));
    strcpy(massage, arr);
    return massage;
}
