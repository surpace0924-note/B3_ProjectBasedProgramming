#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

#define ERROR 0.00001 // 許容誤差

double y(double);
double ybibun(double);

int main(void)
{
    double a = 0.1;
    double b = 1.0;
    double c;
    double xs; //求めようとするx
    int i = 1;

    printf("初期値a:%lf\n", a);
    printf("初期値b:%lf\n", b);
    printf("誤差の設定値:%lf\n", ERROR);
    printf("-計算過程-\n");

    while (1)
    {
        c = (a + b) / 2.0;

        if (y(c) * y(a) < 0)
            b = c;
        else
            a = c;

        printf("%d: %lf\n", i, c); //解を出力

        // 収束判定
        if (fabs(a - b) < ERROR)
            break;

        ++i;
    }
    xs = c;

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
