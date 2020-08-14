#include "Matrix.h"
#include "ErrorCode.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * @brief matrix struct in size NxM.
 */
typedef struct Matrix {
    // matrix pointer
    double** mtrPtr;
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
int matrix_isNull(CPMatrix m) {
    if (m == NULL || m->mtrPtr == NULL)
        return 1;
    return 0;
}


ErrorCode matrix_create(PMatrix* matrix, uint32_t height, uint32_t width) {
    if (height == 0 || width == 0)
        return ERROR_ZERO_SIZE;
    PMatrix m = (PMatrix) malloc(sizeof(Matrix));
    // if malloc failed
    if (m == NULL)
        return ERROR_MEMORY;
    *matrix = m;
    // mallocs the first col of the matrix
    m->mtrPtr = (double **) malloc(sizeof(double *) * (int) height);
    if (m->mtrPtr == NULL) {
        free(m);
        return ERROR_MEMORY;
    }
    // mallocs every line in the mtrix
    for (int i = 0; i < (int) height; i++) {
        m->mtrPtr[i] = (double *) malloc(sizeof(double) * (int) width);
        // if malloc failed
        if (m->mtrPtr[i] == NULL) {
            // free allocated memory
            for (int j = 0; j < i; j++)
                free(m->mtrPtr[j]);
            free(m->mtrPtr);
            free(m);
            // return error
            return ERROR_MEMORY;
        }
    }
    m->height = height;
    m->width = width;
    // function seccessful YAY!!
    return ERROR_SUCCESS;
}

ErrorCode matrix_copy(PMatrix* result, CPMatrix source) {
    // if source has a NULL matrix pointer (or it is NULL)
    if (!matrix_isNull(source))
        return ERROR_NULL;
    // creates a new matrix in the needed sizes
    ErrorCode ec = matrix_create(result, source->height, source->width);
    // if the creation failed
    if (!error_isSuccess(ec))
        return ec;
    // copies the values from the source to the result
    for (int i = 0; i < (int) source->height; i++)
        for (int j = 0; j < (int) source->width; j++)
            (*result)->mtrPtr[i][j] = source->mtrPtr[i][j];
    return ERROR_SUCCESS;
}

void matrix_destroy(PMatrix matrix) {
    // destroys the lines
    for (int i = 0; i < (int) matrix->height; i++)
        free(matrix->mtrPtr[i]);
    // destroys the matrix's pointer
    free(matrix->mtrPtr);
    // destroys the matrix
    free(matrix);
}

ErrorCode matrix_getHeight(CPMatrix matrix, uint32_t* result) {
    // if the matrix's pointer equals to NULL
    if (!matrix_isNull(matrix))
        return ERROR_NULL;
    *result = matrix->height;
    return ERROR_SUCCESS;
}

ErrorCode matrix_getWidth(CPMatrix matrix, uint32_t* result) {
    // if the matrix equals to NULL
    if (!matrix_isNull(matrix))
        return ERROR_NULL;
    *result = matrix->width;
    return ERROR_SUCCESS;
}

ErrorCode matrix_setValue(PMatrix matrix, uint32_t rowIndex, uint32_t colIndex, double value) {
    // if the matrix's pointer equals to NULL or it's lines (or the matrix equals to NULL)
    if (!matrix_isNull(matrix))
        return ERROR_NULL;
    // if the given row or col doesn't exist
    if (rowIndex > matrix->height || colIndex > matrix->width)
        return ERROR_ROW_COL;
    matrix->mtrPtr[(int) rowIndex][(int) colIndex] = value;
    return ERROR_SUCCESS;
}

ErrorCode matrix_getValue(CPMatrix matrix, uint32_t rowIndex, uint32_t colIndex, double* value) {
    // if the matrix's pointer equals to NULL or it's lines (or the matrix equals to NULL)
    if (!matrix_isNull(matrix))
        return ERROR_NULL;
    // if the given row or col doesn't exist
    if (rowIndex > matrix->height || colIndex > matrix->width)
        return ERROR_ROW_COL;
    *value = matrix->mtrPtr[(int) rowIndex][(int) colIndex];
    return ERROR_SUCCESS;
}

ErrorCode matrix_add(PMatrix* result, CPMatrix lhs, CPMatrix rhs) {
    // if one of the matrixs's pointers equals to NULL or it's lines (or the matrix equals to NULL)
    if (!matrix_isNull(rhs) || !matrix_isNull(lhs))
        return ERROR_NULL;
    // if the given row or col doesn't exist
    if (lhs->height != rhs->height || lhs->width != rhs->width)
        return ERROR_ADD_SIZES;
    // creates the result matrix of adding the given ones
    ErrorCode ec = matrix_create(result, lhs->height, lhs->width);
    // if there was an error during the creation of the result
    if (!error_isSuccess(ec))
        return ec;
    // sets the values of the new matrix (adding lhs & rhs)
    for (int i = 0; i < (int) lhs->height; i++)
        for (int j = 0; j < (int) lhs->width; j++)
            (*result)->mtrPtr[i][j] = lhs->mtrPtr[i][j] + rhs->mtrPtr[i][j];
    return ERROR_SUCCESS;
}

ErrorCode matrix_multiplyMatrices(PMatrix* result, CPMatrix lhs, CPMatrix rhs) {
    // if one of the matrixs's pointers equals to NULL or it's lines (or the matrix equals to NULL)
    if (!matrix_isNull(rhs) || !matrix_isNull(lhs))
        return ERROR_NULL;
    // if we can't multiply the matrixes (because of their sizes)
    if (rhs->height != lhs->width)
        return ERROR_ADD_SIZES;
    // creates the result matrix of adding the given ones
    ErrorCode ec = matrix_create(result, lhs->height, rhs->width);
    // if there was an error during the creation of the result
    if (!error_isSuccess(ec))
        return ec;
    // sets the values of the new matrix (multiply lhs & rhs)
    for (int i = 0; i < (int) lhs->height; i++)
        for (int j = 0; j < (int) lhs->width; j++)
            for (int k = 0; k < (int) rhs->width; k++)
                (*result)->mtrPtr[i][j] += lhs->mtrPtr[i][k] * rhs->mtrPtr[k][j];
    return ERROR_SUCCESS;
}

ErrorCode matrix_multiplyWithScalar(PMatrix matrix, double scalar) {
    // if one of the matrixs's pointers equals to NULL or it's lines (or the matrix equals to NULL)
    if (!matrix_isNull(matrix))
        return ERROR_NULL;
    // updates the values of the matrix (multiply by the scalar)
    for (int i = 0; i < (int) matrix->height; i++)
        for (int j = 0; j < (int) matrix->width; j++)
            matrix->mtrPtr[i][j] = matrix->mtrPtr[i][j] * scalar;
    return ERROR_SUCCESS;
}

