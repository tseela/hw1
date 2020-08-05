#include "Matrix.h"
#include "ErrorCode.h"
#include <stdlib.h>
#include <stdio.h>

struct Matrix {
    double** mtrPtr;
    uint32_t height;
    uint32_t width;
} Matrix;

ErrorCode matrix_create(PMatrix* matrix, uint32_t height, uint32_t width) {
    if (height < 1 || width < 1)
        return ERROR_SIZE;
    PMatrix m = (Matrix *)malloc(sizeof(Matrix));
    // if malloc failed
    if (m == NULL)
        return ERROR_MEMORY;
    *matrix = m;
    for (int i = 0; i < height; i++) {
        *(m->mtrPtr + i) = (double *) malloc(sizeof(double) * width);
        // if malloc failed
        if (m->mtrPtr == NULL)
            return ERROR_MEMORY;
    }
    m->height = height;
    m->width = width;
    return ERROR_SUCCESS;
}

ErrorCode matrix_copy(PMatrix* result, CPMatrix source) {
    if (source == NULL || source->mtrPtr == NULL || *(source->mtrPtr) == NULL)
        return ERROR_NULL;
    ErrorCode ec = matrix_create(result, source->height, source->width);
    if (!error_isSuccess(ec))
        return ec;
    for (int i = 0; i < source->height; i++)
        for (int j = 0; j < source->width; j++)
            (*result)->mtrPtr[i][j] = source->mtrPtr[i][j];
    return ERROR_SUCCESS;
}

void matrix_destroy(PMatrix matrix) {
    for (int i = 0; i < matrix.height; i++)
        free(*matrix->mtrPtr);
    free(*matrix);
    free(matrix);
}

ErrorCode matrix_getHeight(CPMatrix matrix, uint32_t* result) {
    if (matrix == NULL)
        return ERROR_NULL;
    *result = matrix->height;
}

ErrorCode matrix_getWidth(CPMatrix matrix, uint32_t* result) {
    if (matrix == NULL)
        return ERROR_NULL;
    *result = matrix->width;
}

ErrorCode matrix_setValue(PMatrix matrix, uint32_t rowIndex, uint32_t colIndex, double value) {
    if (matrix == NULL || matrix->mtrPtr == NULL || *(matrix->mtrPtr) == NULL)
        return ERROR_NULL;
    if (0 > rowIndex || 0 > colIndex || rowIndex >= matrix->height || colIndex >= matrix->width)
        return ERROR_ROW_COLL;
    matrix->mtrPtr[rowIndex][colIndex] = value;
    return ERROR_SUCCESS;
}

ErrorCode matrix_getValue(CPMatrix matrix, uint32_t rowIndex, uint32_t colIndex, double* value) {
    if (matrix == NULL || matrix->mtrPtr == NULL || *(matrix->mtrPtr) == NULL)
        return ERROR_NULL;
    if (0 > rowIndex || 0 > colIndex || rowIndex >= matrix->height || colIndex >= matrix->width)
        return ERROR_ROW_COLL;
    *value = matrix->mtrPtr[rowIndex][colIndex];
    return ERROR_SUCCESS;
}

ErrorCode matrix_add(PMatrix* result, CPMatrix lhs, CPMatrix rhs) {
    if (lhs == NULL || lhs->mtrPtr == NULL || *(lhs->mtrPtr) == NULL || rhs == NULL || rhs->mtrPtr == NULL
        || *(rhs->mtrPtr) == NULL)
        return ERROR_NULL;
    if (lhs->height != rhs->height || lhs->width != rhs->width)
        return ERROR_ADD_SIZES;
    ErrorCode ec = matrix_create(result, lhs->height, lhs->width);
    if (!error_isSuccess(ec))
        return ec;
    for (int i = 0; i < lhs->height; i++)
        for (int j = 0; j < lhs->width; j++)
            (*result)->mtrPtr[i][j] = lhs->mtrPtr[i][j] + rhs->mtrPtr[i][j];
    return ERROR_SUCCESS;
}

ErrorCode matrix_multiplyMatrices(PMatrix* result, CPMatrix lhs, CPMatrix rhs) {
    if (lhs == NULL || lhs->mtrPtr == NULL || *(lhs->mtrPtr) == NULL || rhs == NULL || rhs->mtrPtr == NULL
        || *(rhs->mtrPtr) == NULL)
        return ERROR_NULL;
    if (rhs->height != lhs->width)
        return ERROR_ADD_SIZES;
    ErrorCode ec = matrix_create(result, source.height, source.width);
    if (!error_isSuccess(ec))
        return ec;
    for (int i = 0; i < lhs->height; i++)
        for (int j = 0; j < lhs->width; j++)
            for (int k = 0; k < rhs->width; k++)
                (*result)->mtrPtr[i][j] += lhs->mtrPtr[i][k] * rhs->mtrPtr[k][j];
    return ERROR_SUCCESS;
}

ErrorCode matrix_multiplyWithScalar(PMatrix matrix, double scalar) {
    if (matrix == NULL || matrix->mtrPtr == NULL || *(matrix->mtrPtr) == NULL)
        return ERROR_NULL;
    for (int i = 0; i < matrix->height; i++)
        for (int j = 0; j < matrix->width; j++)
            matrix->mtrPtr[i][j] = matrix->mtrPtr[i][j] * scalar;
    return ERROR_SUCCESS;
}

