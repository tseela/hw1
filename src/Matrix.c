#include "Matrix.h"
#include "ErrorCode.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * @brief matrix struct in size NxM.
 */
typedef struct Matrix {
    // matrix pointer
    double* mtrPtr;
    // the height of the matrix
    uint32_t height;
    // the width of the matrix
    uint32_t width;
} Matrix;

/**
 * @brief check if a matrix's pointer is NULL or if its mtrPtr is NULL.
 * 
 * @param m - a constant pointer to a matrix
 * @return int - 0 if its not NULL
 *               1 if it is NULL
 */
bool matrix_isNull(CPMatrix matrix) {
    return (matrix == NULL || matrix->mtrPtr == NULL);
}


ErrorCode matrix_create(PMatrix* matrix, uint32_t height, uint32_t width) {
    if (matrix == NULL) {
        return ERROR_NULL_PTR;
    }
    if (height == 0 || width == 0) {
        return ERROR_ZERO_SIZE;
    }
    PMatrix m = (PMatrix) malloc(sizeof(Matrix));
    // if malloc failed
    if (m == NULL) {
        return ERROR_MEMORY;
    }
    // allocates the matrix's array
    m->mtrPtr = (double *) calloc(height * width, sizeof(double));
    if (m->mtrPtr == NULL) {
        free(m);
        return ERROR_MEMORY;
    }
    m->height = height;
    m->width = width;
    *matrix = m;
    // function seccessful YAY!!
    return ERROR_SUCCESS;
}

ErrorCode matrix_copy(PMatrix* result, CPMatrix source) {
    // if source has a NULL matrix pointer (or it is NULL)
    if (matrix_isNull(source)) {
        return ERROR_NULL_PTR;
    }
    ErrorCode ec = matrix_create(result, source->height, source->width);
    // if the creation failed
    if (!error_isSuccess(ec)) {
        return ec;
    }
    // copies the values from the source to the result
    for (uint32_t i = 0; i < source->height; ++i) {
        for (uint32_t j = 0; j < source->width; ++j) {
            (*result)->mtrPtr[i * source->width + j] = source->mtrPtr[i * source->width + j];
        }
    }
    (*result)->height = source->height;
    (*result)->width = source->width;
    return ERROR_SUCCESS;
}

void matrix_destroy(PMatrix matrix) {
    if (matrix != NULL) {
        free(matrix->mtrPtr);
    }
    free(matrix);
}

ErrorCode matrix_getHeight(CPMatrix matrix, uint32_t* result) {
    if (matrix_isNull(matrix) || result == NULL) {
        return ERROR_NULL_PTR;
    }
    *result = matrix->height;
    return ERROR_SUCCESS;
}

ErrorCode matrix_getWidth(CPMatrix matrix, uint32_t* result) {
    if (matrix_isNull(matrix) || result == NULL) {
        return ERROR_NULL_PTR;
    }
    *result = matrix->width;
    return ERROR_SUCCESS;
}

ErrorCode matrix_setValue(PMatrix matrix, uint32_t rowIndex, uint32_t colIndex, double value) {
    // if the matrix's pointer equals to NULL or it's lines (or the matrix equals to NULL)
    if (matrix_isNull(matrix)) {
        return ERROR_NULL_PTR;
    }
    // if the given row or col doesn't exist
    if (rowIndex >= matrix->height || colIndex >= matrix->width) {
        return ERROR_OUT_OF_RANGE;
    }
    matrix->mtrPtr[rowIndex * matrix->width + colIndex] = value;
    return ERROR_SUCCESS;
}

ErrorCode matrix_getValue(CPMatrix matrix, uint32_t rowIndex, uint32_t colIndex, double* value) {
    // if the matrix's pointer equals to NULL or it's lines (or the matrix equals to NULL)
    if (matrix_isNull(matrix) || value == NULL) {
        return ERROR_NULL_PTR;
    }
    // if the given row or col doesn't exist
    if (rowIndex >= matrix->height || colIndex >= matrix->width) {
        return ERROR_OUT_OF_RANGE;
    }
    *value = matrix->mtrPtr[rowIndex * matrix->width + colIndex];
    return ERROR_SUCCESS;
}

ErrorCode matrix_add(PMatrix* result, CPMatrix lhs, CPMatrix rhs) {
    // if one of the matrices's pointers equals to NULL or it's lines (or the matrix equals to NULL)
    if (matrix_isNull(rhs) || matrix_isNull(lhs)) {
        return ERROR_NULL_PTR;
    }
    // if the given row or col doesn't exist
    if (lhs->height != rhs->height || lhs->width != rhs->width) {
        return ERROR_MATRIX_SIZE;
    }
    ErrorCode ec = matrix_create(result, lhs->height, lhs->width);
    if (!error_isSuccess(ec))
        return ec;
    // sets the values of the new matrix (adding lhs & rhs)
    for (uint32_t i = 0; i < lhs->height; ++i) {
        for (uint32_t j = 0; j < lhs->width; ++j) {
            (*result)->mtrPtr[i * lhs->width + j] = lhs->mtrPtr[i * lhs->width + j] + rhs->mtrPtr[i * lhs->width + j];
        }
    }
    return ERROR_SUCCESS;
}

ErrorCode matrix_multiplyMatrices(PMatrix* result, CPMatrix lhs, CPMatrix rhs) {
    // if one of the matrices's pointers equals to NULL or it's lines (or the matrix equals to NULL)
    if (matrix_isNull(rhs) || matrix_isNull(lhs)) {
        return ERROR_NULL_PTR;
    }
    // if we can't multiply the matrices (because of their sizes)
    if (rhs->height != lhs->width) {
        return ERROR_MATRIX_SIZE;
    }
    ErrorCode ec = matrix_create(result, lhs->height, rhs->width);
    if (!error_isSuccess(ec))
        return ec;
    // sets the values of the new matrix (multiply lhs & rhs)
    for (uint32_t i = 0; i < lhs->height; ++i) {
        for (uint32_t j = 0; j < lhs->width; ++j) {
            for (uint32_t k = 0; k < rhs->width; k++) {
                (*result)->mtrPtr[i * rhs->width + j] += lhs->mtrPtr[i * lhs->width + k] * rhs->mtrPtr[k * rhs->width + j];
            }
        }
    }
    return ERROR_SUCCESS;
}

ErrorCode matrix_multiplyWithScalar(PMatrix matrix, double scalar) {
    // if one of the matrices's pointers equals to NULL or it's lines (or the matrix equals to NULL)
    if (matrix_isNull(matrix)) {
        return ERROR_NULL_PTR;
    }
    // updates the values of the matrix (multiply by the scalar)
    for (uint32_t i = 0; i < matrix->height; ++i) {
        for (uint32_t j = 0; j < matrix->width; ++j) {
            matrix->mtrPtr[i * matrix->width + j] = matrix->mtrPtr[i * matrix->width + j] * scalar;
        }
    }
    return ERROR_SUCCESS;
}