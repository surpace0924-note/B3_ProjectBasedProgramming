#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define N 4          // データ点数
#define DELTA_X 0.01 // 分割幅

int main()
{
    int i, j;
    double a, tmp, sum;
    double x[N] = {1.0, 2.0, 3.0, 4.0}; // ここにデータ点の座標を入力
    double y[N] = {-0.4, -0.1, 0.3, 0.8};

    a = 0; // 求めたいyの点

    sum = 0;
    for (i = 0; i < N; i++)
    {
        tmp = 1.0;
        for (j = 0; j < N; j++)
        {
            if (i != j)
                tmp *= (a - y[j]) / (y[i] - y[j]);
        }
        sum += x[i] * tmp;
    }

    printf("y=%lfでのyの値は%lf\n", a, sum);

    return 0;
}
