# ex1
Author: Tseela

e-mail: tseelagamzo@gmail.com



## Explanation about the project?
This project is a library that represents a Matrix object.

The object includes two modules - Matrix & ErrorCode.



### ErrorCode.h
In order to track the success of the matrix's functions I used an ErrorCode module.

the module includes the following enum:

{
typedef enum {

    // No error
    
    ERROR_SUCCESS = 0,
    
    // malloc faild
    
    ERROR_MEMORY = 1,
    
    // the user gave the function a NULL pointer
    
    ERROR_NULL = 2,
    
    // the user tries to approach a row or a col that doesn't exists
    
    ERROR_ROW_COL = 3,
    
    // the user tries to add two matrixes from different sizes
    
    ERROR_ADD_SIZES = 4,
    
    // the user tries to multiply two matrixes that can't be multiplied
    
    ERROR_MULT_SIZES = 5,
    
    // matrix's width or height can't be 0
    
    ERROR_ZERO_SIZE = 6
    
} ErrorCode;
}

Includes the functions:

> error_isSuccess             // Recieves an ErrorCode and returns 1 if it indicates that there wasn't any error or 0 if there was one.
>
> error_getErrorMessage       // Recieves an ErrorCode and return a string which explains why the error accured.



### Matrix.h
Includes some typedefs:

> PMatrix     // A pointer to the matrix ('typedef struct Matrix* PMatrix')
>
> CPMatrix    // A constant pointer to the matrix ('typedef const struct Matrix* CPMatrix')
>
Includes the folowing functions:
>
> matrix_create               // Recieves a pointer to PMatrix, height and width. Creates a new matrix (and points the given pointer to it) and returns an ErrorCode according to the success of the function.
>
> matrix_copy                 // Recieves a pointer to PMatrix (which will be our new copy) and a CPMatrix that we will copy. The function creates a deep copy of the given CPMatrix and returns an ErrorCode according to the success of the function.
>
> matrix_destroy              // Recieves a PMatrix and destroys it (free all allocated memory). It's important to destroy the matrices you use at the end of the program because we want to prevent a [memory leak](https://en.wikipedia.org/wiki/Memory_leak).
>
> matrix_getHeight            // Recieves a CPMatrix and a pointer to 'unit32_t' number. Updates the number to be the height of the matrix and returns an ErrorCode according to  the success of the function.
>
> matrix_getWidth             // Recieves a CPMatrix and a pointer to 'unit32_t' number. Updates the number to be the width of the matrix and returns an ErrorCode according to the success of the function.
>
> matrix_setValue             // Recieves a PMatrix, rowIndex, colIndex and a value (double type). Updates the requested cell of the matrix to be the given value and returns an ErrorCode according to the success of the function.
>
> matrix_getValue             // Recieves a PMatrix, rowIndex, colIndex and a pointer to a value (double type). Updates the value to be the value in requested cell of the matrix and returns an ErrorCode according to the success of the function.
>
> matrix_add                  // Recieves a PMatrix pointer and two CPMatrices. Updates the PMatrix pointer to be their sum and return an ErrorCode according to the success of the function.
>
> matrix_multiplyMatrices     // Recieves a PMatrix pointer and two CPMatrices (left one and right one). Updates the PMatrix pointer to be the result of the multiplience of the given matrices and returns an ErrorCode according to the success of the function.
>
> matrix_multiplyWithScalar   // Recieves a PMatrix and a number (double type). Nultiplies the PMatrix by the given number and returns an ErrorCode according to the success of the function.


for more information about 'Matrix.h' & 'ErrorCode.h' check the files (find them on branch master).



## Testing
To make sure my code has no bugs I created a testing file and ran my code with it in addition to two other test codes.

If you want to see my test files you can upload them [here](http://www.upfile.co.il/file/855970208.html), [here](http://www.upfile.co.il/file/241469518.html) and [here](https://d1b10bmlvqabco.cloudfront.net/paste/k2aj7u5l1um5bs/e34dfae03f1116d982cf64b12c73408c606d9e00d136a563be625ca1ae2d34ac/tester.c).



## BYE BYE <3
