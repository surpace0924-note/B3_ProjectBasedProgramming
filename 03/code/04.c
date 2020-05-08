#include <stdio.h>
#define Na1 3
#define Na2 2
#define Nb1 2
#define Nb2 4
void mul_mat(int a[Na1][Na2], int b[Nb1][Nb2], int c[Na1][Nb2]);

int main(void)
{
    int a[Na1][Na2] = {{1, 2},
                       {1, 3},
                       {2, 4}};
    int b[Nb1][Nb2] = {{1, 0, 2, 3},
                       {-1, 1, -2, 1}};
    int c[Na1][Nb2];
    int i, j;

    mul_mat(a, b, c); // 行列の掛け算

    printf("行列の積 a*b = \n");
    for (i = 0; i < Na1; i++)
    {
        for (j = 0; j < Nb2; j++)
        {
            printf("%4d", c[i][j]);
        }
        printf("\n");
    }

    return 0;
}

void mul_mat(int a[Na1][Na2], int b[Nb1][Nb2], int c[Na1][Nb2])
{
    int i, j, k;
    // cの初期化
    for (i = 0; i < Na1; i++)
    {
        for (j = 0; j < Nb2; j++)
        {
            c[i][j] = 0;
        }
    }

    for (i = 0; i < Na1; i++)
    {
        for (j = 0; j < Na2; j++)
        {
            for (k = 0; k < Nb2; k++)
            {
                c[i][k] += a[i][j] * b[j][k];
            }
        }
    }
}
