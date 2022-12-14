/*
    4. Write a program to multiply two matrices.
*/

#include <stdio.h>

#define ROW 3
#define COL 3

void matrixInput(int mat[][COL]); // Function to input elements in matrix
void matrixPrint(int mat[][COL]); // Function to print elements of matrix
void matrixMultiply(int mat1[][COL], int mat2[][COL], int res[][COL]); // Function to multiply two matrices

int main() {
    int mat1[ROW][COL];
    int mat2[ROW][COL];
    int product[ROW][COL];
    printf("Enter elements in first matrix of size %dx%d\n", ROW, COL);
    matrixInput(mat1);
    printf("Enter elements in second matrix of size %dx%d\n", ROW, COL);
    matrixInput(mat2);
    matrixMultiply(mat1, mat2, product);
    printf("Product of both matrices is : \n");
    matrixPrint(product);
    return 0;
}

void matrixInput(int mat[][COL]) {
    int row, col;
    for (row = 0; row < ROW; row++) {
        for (col = 0; col < COL; col++) {
            scanf("%d", (*(mat + row) + col));
        }
    }
}

void matrixPrint(int mat[][COL]) {
    int row, col;
    for (row = 0; row < ROW; row++) {
        for (col = 0; col < COL; col++) {
            printf("%d ", *(*(mat + row) + col));
        }
        printf("\n");
    }
}

void matrixMultiply(int mat1[][COL], int mat2[][COL], int res[][COL]) {
    int row, col, i;
    int sum;
    for (row = 0; row < ROW; row++) {
        for (col = 0; col < COL; col++) {
            sum = 0;
            for (i = 0; i < COL; i++) {
                sum += (*(*(mat1 + row) + i)) * (*(*(mat2 + i) + col));
            }
            *(*(res + row) + col) = sum;
        }
    }
}