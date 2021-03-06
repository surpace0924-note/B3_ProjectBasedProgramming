#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <limits.h>
#include <math.h>

#define N 1000000

double f(double x);

int main(void)
{
    double y[N + 1];
    double a = 0.0, b = 1; // 積分範囲（0から1までの上半分（0<angle<pi/2）だけ求めてあとで4倍する）
    double z = 0.0, h = 0.0, x, s;
    unsigned long int i;

    h = (b - a) / (double)N;

    for (i = 0; i <= N; i++)
    {
        x = a + h * (double)i;
        y[i] = f(x);
    }

    for (i = 1; i < N; i++)
    {
        z += 2.0 * y[i];
    }

    s = (h / 2.0) * (y[0] + z + y[N]);

    s *= 4;

    printf("積分結果　　: %.10lf[cm^2]\r\n", s);
    printf("求めた円周率: %.10lf\r\n", s);
    return 0;
}

double f(double x)
{
    return sqrt(1 - x * x);
}
