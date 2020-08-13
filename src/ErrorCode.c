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
        case ERROR_ROW_COL:
            char arr[] = "ERROR! Requested row or col does not exists in the given matrix.";
            break;
        case ERROR_ADD_SIZES:
            char arr[] = "ERROR! You can't add up matrices from different sizes.";
            break;
        case ERROR_MULT_SIZES:
            char arr[] = "ERROR! Can't multiply the given matrices (sizes does not match).";
            break;
        default:
            char arr[] = "ERROR! An undefined error occured.";
    }
    char* massage = (char*) malloc(sizeof(char) * strlen(arr));
    strcpy(massage, arr);
    return massage;
}
