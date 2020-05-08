#include <stdio.h>
#define N 10 // 配列の要素数

// グローバル変数の配列x
double x[N] = {3.5, -4.0, 7.5, 2.5, 6.0, -8.0, 9.5, 1.0, 0, 5.5};

// ソート関数
void sort(int n);

int main(void)
{
    int i;

    // ソート
    sort(N);

    // 表示
    for (i = 0; i < N; i++)
    {
        printf("x[%d] = %.2lf\n", i, x[i]);
    }
}

// ソート関数
void sort(int n)
{
    int i, j;
    double tmp;

    for (i = 0; i < n; ++i)
    {
        for (j = i + 1; j < n; ++j)
        {
            if (x[i] < x[j])
            {
                tmp = x[i];
                x[i] = x[j];
                x[j] = tmp;
            }
        }
    }
}
