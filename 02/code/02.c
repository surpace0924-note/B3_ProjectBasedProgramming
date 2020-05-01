#include <stdio.h>
#define N 10 // 配列の要素数

// 配列要素の交換
void swap(double *a, double *b)
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

int main(void)
{
    int i, j;
    double x[N] = {3.5, -4.0, 7.5, 2.5, 6.0, -8.0, 9.5, 1.0, 0, 5.5};
    double tmp;

    // ソート
    for (i = 0; i < N; ++i)
    {
        for (j = i + 1; j < N; ++j)
        {
            if (x[i] < x[j])
            {
                tmp = x[i];
                x[i] = x[j];
                x[j] = tmp;
            }
        }
    }

    // 表示
    for (i = 0; i < N; i++)
    {
        printf("x[%d] = %.2lf\n", i, x[i]);
    }
}
