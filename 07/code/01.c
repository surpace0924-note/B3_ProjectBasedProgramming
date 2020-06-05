#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define N 4          // データ点数
#define DELTA_X 0.01 // 分割幅

int main()
{
    int i, j;
    double a, tmp, sum;
    double x[N] = {1.0, 2.0, 3.0, 4.0}; // ここにデータ点の座標を入力
    double y[N] = {18.0, 36.0, -4.0, 30.0};

    // printf("補間点xを入力\n x=");
    // scanf("%lf", &a);

    a = x[0];
    while (a <= x[N - 1])
    {
        sum = 0;
        for (i = 0; i < N; i++)
        {
            tmp = 1.0; // i項目を求めたい
            for (j = 0; j < N; j++)
            {
                if (i != j)
                    tmp *= (a - x[j]) / (x[i] - x[j]); // y[i]にy[i]の係数をかける。係数の法則性に注目。
            }
            sum += y[i] * tmp; // i項目の値を0からN-1まで足すと最終的な答えになる。
        }

        // printf("x=%lfでの値は%lf\n", a, sum);
        printf("%lf, %lf\n", a, sum);

        a += DELTA_X;
    }

    return 0;
}
