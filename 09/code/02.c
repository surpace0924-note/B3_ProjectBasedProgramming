#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <limits.h>
#include <math.h>

#define N 100000

long double f(long double x);

int main(void)
{
    long double y[N + 1];
    long double a = 0.0, b = 5; // 積分範囲（x=5の時，exp(-x^2) は1.39e-11となり，十分小さいと判断した．また，偶関数なので半分だけ計算してあとで2倍する）
    long double z = 0.0, h = 0.0, x, s;
    unsigned int i;

    h = (b - a) / (long double)N;

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

    s *= 2.0;
    s /= sqrt(M_PI);

    printf("答え: %Lf\r\n", s);
    return 0;
}

long double f(long double x)
{
    return exp(-1 * pow(x, 2.0));
}
