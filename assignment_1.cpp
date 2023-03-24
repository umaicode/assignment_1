#include <stdio.h>
#include <stdlib.h>
#include "time.h"
#define ROWS 3
#define COLS 4
#define BROWS 4
#define BCOLS 5
#define CROWS 3
#define CCOLS 5

bool showMatrix(int[][COLS], int);
bool getMatrix(int (*arr)[COLS], int rows);
bool showMatrixB(int[][BCOLS], int);
bool getMatrixB(int (*arr)[BCOLS], int rows);
bool showMatrixC(int[][CCOLS], int);
bool multiplyMatrix(int[][COLS], int, int, int[][BCOLS], int, int, int[][CCOLS], int, int);
bool addMatrix(int[][COLS], int, int[][COLS], int, int[][COLS], int);

int main()
{
    srand(time(NULL));
    int a[ROWS][COLS];
    int a1[ROWS][COLS];
    int a2[ROWS][COLS];
    int b[BROWS][BCOLS];
    int c[CROWS][CCOLS];

    getMatrix(a, ROWS);
    showMatrix(a, ROWS);
    getMatrix(a1, ROWS);
    showMatrix(a1, ROWS);

    addMatrix(a, ROWS, a1, ROWS, a2, ROWS);
    showMatrix(a2, CROWS);

    getMatrixB(b, BROWS);
    showMatrixB(b, BROWS);

    multiplyMatrix(a, ROWS, COLS, b, BROWS, BCOLS, c, CROWS, CCOLS);
    showMatrixC(c, CROWS);
    system("pause");
    return 0;
}

bool multiplyMatrix(int (*a)[COLS], int ar, int ac, int (*b)[BCOLS], int br, int bc, int (*c)[CCOLS], int cr, int cc)
{
    if (ac != br)
        return false;

    for (int i = 0; i < cr; i++)
    {
        for (int j = 0; j < cc; j++)
        {
            *(*(c + i) + j) = 0;
        }
    }

    for (int i = 0; i < ar; i++)
    {
        for (int j = 0; j < bc; j++)
        {
            for (int k = 0; k < ac; k++)
            {
                *(*(c + i) + j) += *(*(a + i) + k) * *(*(b + k) + j);
            }
        }
    }
    return true;
}

bool addMatrix(int (*a)[COLS], int ar, int (*a1)[COLS], int ar1, int (*a2)[COLS], int ar2)
{
    for (int i = 0; i < ar; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            *(*(a2 + i) + j) = *(*(a + i) + j) + *(*(a1 + i) + j);
        }
    }
    return true;
}

bool getMatrix(int (*arr)[COLS], int rows)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            *(*(arr + i) + j) = rand() % 10;
        }
    }
    return true;
}

bool getMatrixB(int (*arr)[BCOLS], int rows)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < BCOLS; j++)
        {
            *(*(arr + i) + j) = rand() % 10;
        }
    }
    return true;
}

bool showMatrix(int (*arr)[COLS], int rows)
{
    printf("\n");
    printf(" matrix row = %d, col = %d\n", rows, COLS);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            printf("%4d", *(*(arr + i) + j));
        }
        printf("\n");
    }
    return true;
}

bool showMatrixB(int (*arr)[BCOLS], int rows)
{
    printf("\n");
    printf(" matrix row = %d, col = %d\n", rows, BCOLS);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < BCOLS; j++)
        {
            printf("%4d", *(*(arr + i) + j));
        }
        printf("\n");
    }
    return true;
}

bool showMatrixC(int (*arr)[CCOLS], int rows)
{
    printf("\n");
    printf(" matrix row = %d, col = %d\n", rows, CCOLS);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < CCOLS; j++)
        {
            printf("%4d ", *(*(arr + i) + j));
        }
        printf("\n");
    }
    return true;
}