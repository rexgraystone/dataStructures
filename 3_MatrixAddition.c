/*
    3. Write a program to add two matrices.
*/

#include <stdio.h>

#define ROW  3
#define COL  3

void matrixInput(int mat[][COL]);
void matrixPrint(int mat[][COL]);
void matrixAdd(int mat1[][COL], int mat2[][COL], int res[][COL]);

int main()
{
    int mat1[ROW][COL], mat2[ROW][COL], res[ROW][COL];
    printf("Enter elements in first matrix of size %dx%d: \n", ROW, COL);
    matrixInput(mat1);
    printf("\nEnter elements in second matrix of size %dx%d: \n", ROW, COL);
    matrixInput(mat2);
    matrixAdd(mat1, mat2, res);
    printf("\nSum of first and second matrix: \n");
    matrixPrint(res);
    return 0;
}

void matrixInput(int mat[][COL])
{
    int i, j;
    for (i = 0; i < ROW; i++)
    {
        for (j = 0; j < COL; j++)
        {
            scanf("%d", (*(mat + i) + j));
        }
    }
}

void matrixPrint(int mat[][COL])
{
    int i, j;
    for (i = 0; i < ROW; i++)
    {
        for (j = 0; j < COL; j++)
        {
            printf("%d ", *(*(mat + i) + j));
        }
        printf("\n");
    }
}

void matrixAdd(int mat1[][COL], int mat2[][COL], int res[][COL])
{
    int i, j; 
    for (i = 0; i < ROW; i++)
    {
        for (j = 0; j < COL; j++)
        {
            *(*(res + i) + j) = *(*(mat1 + i) + j) + *(*(mat2 + i) + j);
        }
    }
}
