// 74. Set Matrix Zeroes
// 给定一个 m x n 的矩阵，如果一个元素为 0 ，则将其所在行和列的所有元素都设为 0 。请使用 原地 算法。
// 示例 1：
// 输入：matrix = [[1,1,1],[1,0,1],[1,1,1]]
// 输出：[[1,0,1],[0,0,0],[1,0,1]]

// 示例 2：
// 输入：matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
// 输出：[[0,0,0,0],[0,4,5,0],[0,3,1,0]]
#include <stdio.h>
#include <stdlib.h>

void setZeroes(int** matrix, int matrixSize, int* matrixColSize){
    int zero_in_first_row = 0;
    int zero_in_first_column = 0;
    int i;
    int j;

    for (j=0; j<matrixColSize[0]; j++) {
        if (matrix[0][j] == 0) {
            zero_in_first_row = 1;
            break;
        }
    } 
    for (i=0; i<matrixSize; i++) {
        if (matrix[i][0] == 0) {
            zero_in_first_column = 1;
            break;
        } 
    }
    for (i=1; i<matrixSize; i++) {
        for (j=1; j<matrixColSize[0]; j++) { // 每一行的元素列数是一样多的，索性直接用matrixColSize[0]
            if (matrix[i][j] == 0) { // 找到元素0，第一行，第一列上进行标记
                matrix[0][j] = 0;
                matrix[i][0] = 0;
            }
        }
    }
    for (i=1; i<matrixSize; i++) {
        for (j=1; j<matrixColSize[0]; j++) {
            // if (matrix[0][j]*matrix[i][0] == 0) { // 这里用乘法会有溢出的风险，还是老老实实的来
            if (matrix[0][j]==0 || matrix[i][0]==0)
                matrix[i][j] = 0;
            }
        }
    }
    if (zero_in_first_row == 1) {
        for (j=0; j<matrixColSize[0]; j++) {
            matrix[0][j] = 0;
        }
    } 
    if (zero_in_first_column == 1) {
        for (i=0; i<matrixSize; i++) {
            matrix[i][0] = 0;
        }
    } 
    return;
}