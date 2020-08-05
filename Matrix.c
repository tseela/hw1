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
    double** mtrPtr;
    uint32_t height;
    uint32_t width;
};

ErrorCode matrix_create(PMatrix* matrix, uint32_t height, uint32_t width) {
    if (height < 1 || width < 1)
        return ERROR_SIZE;
    matrix = (PMatrix *)malloc(sizeof(Dictionary));
    // if malloc failed
    if (matrix == NULL)
        return ERROR_MEMORY;
    for (int i = 0; i < height; i++) {
        *(matrix->mtrPtr + i) = (double *) malloc(sizeof(double) * width);
        // if malloc failed
        if (matrix->mtrPtr == NULL)
            return ERROR_MEMORY;
    }
    matrix->height = height;
    matrix.width = width;
    return ERROR_SUCCESS;
}

ErrorCode matrix_copy(PMatrix* result, CPMatrix source) {
    if (source == NULL || source == NULL)
        return ERROR_NULL;
    ErrorCode ec = matrix_create(result, source.height, source.width);
    if (!error_isSuccess(ec))
        return ec;
    for (int i = 0; i < source.height; i++)
        for (int j = 0; j < source.width; j++)
            result->mtrPtr[i][j] = source.mtrPtr[i][j];
    return ERROR_SUCCESS;
}

void matrix_destroy(PMatrix matrix) {
    for (int i = 0; i < matrix.height; i++)
        free(*matrix.mtrPtr);
    free(matrix.mtrPtr);
    free(matrix);
}

ErrorCode matrix_getHeight(CPMatrix matrix, uint32_t* result) {}

ErrorCode matrix_getWidth(CPMatrix matrix, uint32_t* result) {}

ErrorCode matrix_setValue(PMatrix matrix, uint32_t rowIndex, uint32_t colIndex, double value) {}

ErrorCode matrix_getValue(CPMatrix matrix, uint32_t rowIndex, uint32_t colIndex, double* value) {}

ErrorCode matrix_add(PMatrix* result, CPMatrix lhs, CPMatrix rhs) {}

ErrorCode matrix_multiplyMatrices(PMatrix* result, CPMatrix lhs, CPMatrix rhs) {}

ErrorCode matrix_multiplyWithScalar(PMatrix matrix, double scalar) {}

