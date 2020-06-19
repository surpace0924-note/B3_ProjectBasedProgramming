#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

#define N 100

long double f(long double x);

int main(void)
{
    long double y[N + 1];
    long double a = 0.0, b = M_PI; // 積分範囲
    long double z = 0.0, h = 0.0, x, s;
    int i;

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

    printf("答え: %Lf\r\n", s);
    return 0;
}

long double f(long double x)
{
    return sin(x);
}
