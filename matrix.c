
#include <stdio.h>

// Function to read a matrix
void readMatrix(int a[10][10], int r, int c)
{
    int i, j;

    for(i = 0; i < r; i++)
    {
        for(j = 0; j < c; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
}

// Function to display a matrix
void displayMatrix(int a[10][10], int r, int c)
{
    int i, j;

    for(i = 0; i < r; i++)
    {
        for(j = 0; j < c; j++)
        {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }
}

// Function for matrix addition
void addMatrix(int a[10][10], int b[10][10],
               int r, int c)
{
    int sum[10][10], i, j;

    for(i = 0; i < r; i++)
    {
        for(j = 0; j < c; j++)
        {
            sum[i][j] = a[i][j] + b[i][j];
        }
    }

    printf("\nMatrix Addition:\n");
    displayMatrix(sum, r, c);
}

// Function for matrix multiplication
void multiplyMatrix(int a[10][10], int b[10][10],
                    int r1, int c1, int c2)
{
    int product[10][10] = {0};
    int i, j, k;

    for(i = 0; i < r1; i++)
    {
        for(j = 0; j < c2; j++)
        {
            for(k = 0; k < c1; k++)
            {
                product[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    printf("\nMatrix Multiplication:\n");
    displayMatrix(product, r1, c2);
}

// Function for matrix transpose
void transposeMatrix(int a[10][10], int r, int c)
{
    int trans[10][10], i, j;

    for(i = 0; i < r; i++)
    {
        for(j = 0; j < c; j++)
        {
            trans[j][i] = a[i][j];
        }
    }

    printf("\nMatrix Transpose:\n");
    displayMatrix(trans, c, r);
}

int main()
{
    int a[10][10], b[10][10];
    int r1, c1, r2, c2;

    printf("Enter rows and columns of Matrix A: ");
    scanf("%d %d", &r1, &c1);

    printf("Enter elements of Matrix A:\n");
    readMatrix(a, r1, c1);

    printf("Enter rows and columns of Matrix B: ");
    scanf("%d %d", &r2, &c2);

    printf("Enter elements of Matrix B:\n");
    readMatrix(b, r2, c2);

    // Matrix Addition
    if(r1 == r2 && c1 == c2)
    {
        addMatrix(a, b, r1, c1);
    }
    else
    {
        printf("\nAddition is not possible.\n");
    }

    // Matrix Multiplication
    if(c1 == r2)
    {
        multiplyMatrix(a, b, r1, c1, c2);
    }
    else
    {
        printf("\nMultiplication is not possible.\n");
    }

    // Transpose of Matrix A
    transposeMatrix(a, r1, c1);

    // Transpose of Matrix B
    transposeMatrix(b, r2, c2);

    return 0;
}
