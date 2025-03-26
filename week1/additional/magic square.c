#include <stdio.h>

int rowSum(int matrix[][10], int n, int row) {
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += matrix[row][i];
    return sum;
}
int colSum(int matrix[][10], int n, int col) {
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += matrix[i][col];
    return sum;
}

//to check if magic square
int MagicSquare(int matrix[][10], int n) {
    int sum = rowSum(matrix, n, 0);

    //sum of each row
    for (int i = 1; i < n; i++)
        if (rowSum(matrix, n, i) != sum)
            return 0;
    //sum of each column
    for (int i = 0; i < n; i++)
        if (colSum(matrix, n, i) != sum)
            return 0;
    //sum of diagonals
    int diagSum = 0;
    for (int i = 0; i < n; i++)
        diagSum += matrix[i][i];
    if (diagSum != sum)
        return 0;
    // Check sum of the other diagonal
    int diagSum2 = 0;
    for (int i = 0; i < n; i++)
        diagSum2 += matrix[i][n -i-1];
    if (diagSum2 != sum)
        return 0;
    // If all true - magic square
    return 1;
}

int main() {
    int matrix[10][10];
    int n;
    printf("size of the square matrix: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &matrix[i][j]);

    if (MagicSquare(matrix, n))
        printf("magic square.\n");
    else
        printf("not a magic square.\n");
    return 0;
}
