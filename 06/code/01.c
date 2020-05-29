#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

#define ERROR 0.00001 // 許容誤差

double y(double);
double ybibun(double);

int main(void)
{
    double a = 1.0;
    double xs; //求めようとするx
    int i = 1;

    printf("初期値:%lf\n", a);
    printf("誤差の設定値:%lf\n", ERROR);
    printf("-計算過程-\n");

    while (1)
    {
        xs = a - y(a) / ybibun(a);
        printf("%d: %lf\n", i, xs); //解を出力

        // 収束判定
        if (fabs(a - xs) < ERROR)
            break;

        a = xs;
        ++i;
    }

    printf("-------------\n");
    printf("解=%lf\n", xs); //解を出力
    return 0;
}

double y(double x) //関数y=log(x)+sqrt(x) の定義
{
    return (log(x) + sqrt(x));
}

double ybibun(double x) //関数y' の定義
{
    return ((sqrt(x) + 2) / (2 * x));
}