#include <stdio.h>
#define N 10 // 配列の要素数

int main(void)
{
    int i;
    double x[N] = {3.5, -4.0, 7.5, 2.5, 6.0, -8.0, 9.5, 1.0, 0, 5.5};
    double max, min;
    max = min = x[0];

    // ピックアップ
    for (i = 0; i < N; i++)
    {
        max = x[i] > max ? x[i] : max;
        min = x[i] < min ? x[i] : min;
    }

    // 表示
    for (i = 0; i < N; i++)
    {
        printf("x[%d] = %.2lf\n", i, x[i]);
    }
    printf("最大値 = %.2lf 最小値 = %.2lf\n", max, min);
}
