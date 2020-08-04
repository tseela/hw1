#include "Matrix.h"
#include "ErrorCode.h"
#include <stdlib.h>
#include <stdio.h>

struct Matrix* {
    double** mtrPtr;
    uint32_t height;
    uint32_t width;
};

const struct Matrix* {

};

ErrorCode matrix_create(PMatrix* matrix, uint32_t height, uint32_t width) {
    if (height < 1 && width < 1)
        return ERROR_HEIGHT_WIDTH;
    if (height < 1)
        return ERROR_HEIGHT;
    if (width < 1)
        return ERROR_WIDTH;
    matrix = (PMatrix*)malloc(sizeof(Dictionary));
    // if malloc failed
    if (matrix == NULL)
        return ERROR_MEMORY;
    for (int i = 0; i < height; i++) {
        (matrix->mtrPtr + i)* = (double *) malloc(double.size() * width); // fix it!!!!
        // if malloc failed
        if (matrix->mtrPtr == NULL)
            return ERROR_MEMORY;
    }
    matrix->height = height;
    matrix.width = width;
}
