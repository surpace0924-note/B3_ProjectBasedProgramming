/* サンプルプログラム2 */
#include <stdio.h>
#define Na1 3
#define Na2 4
#define Nb1 4
#define Nb2 2

int main(void)
{
    int i, j, k;
    int a[Na1][Na2] = {{1, -2, 2, 1},
                       {1, 0, 2, 3},
                       {3, 6, 1, 2}};

    int b[Nb1][Nb2] = {{4, 7},
                       {-2, 4},
                       {3, 1},
                       {1, 4}};

    int ans[Na1][Nb2] = {{0}};

    for (i = 0; i < Na1; i++)
    {
        for (j = 0; j < Na2; j++)
        {
            for (k = 0; k < Nb2; k++)
            {
                ans[i][k] += a[i][j] * b[j][k];
            }
        }
    }

    printf("行列の積 a×b\r\n");
    for (i = 0; i < Na1; i++)
    {
        for (j = 0; j < Nb2; j++)
        {
            printf("%5d", ans[i][j]);
        }
        printf("\n");
    }
}
