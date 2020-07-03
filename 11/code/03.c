#include <stdio.h>
#include <math.h>

#define END_T 2e-6
#define div_num 1000 // (int)(END_T / H)
#define N 9

#define C 20e-9 / 5
#define L 2e-6 / 5
#define R 10

double func(double x[N], double t, int n);
void calInt(double x[div_num], double dt, double y[div_num]);

double init_vector[N] = {1000, 1000, 1000, 1000, 1000, 0, 0, 0, 0};

int main(void)
{
    int i, j;
    double t = 0;
    double h = END_T / div_num;
    double vr[div_num] = {0};
    double x[div_num][N] = {{0}};
    for (i = 0; i < N; ++i)
        x[0][i] = init_vector[i];

    for (i = 0; i < div_num; ++i)
    {
        for (j = 0; j < N; ++j)
        {
            x[i + 1][j] = x[i][j] + h * func(x[i], t, j);
        }
        t += h;
    }

    for (i = 0; i < div_num; ++i)
        vr[i] += x[i][0];

    for (i = 0; i < div_num; ++i)
    {
        printf("%.10lf,%lf\r\n", (double)(h * i), vr[i]);
    }

    return 0;
}

double func(double x[N], double t, int n)
{
    if (n == 0)
        return -1 * x[n + N / 2 + 1] / C;

    if (n == N / 2 + 1)
        return (x[n - N / 2 - 1] - x[n - N / 2]) / L;

    if (n < N / 2 + 1)
    {
        // 電圧
        return (x[n + N / 2 + 1] - x[n + N / 2]) / C;
    }
    else
    {
        // 電流
        if (n == N - 1)
            printf("%lf,%lf\r\n", x[n - N / 2 - 1], x[n]);
        return (x[n - N / 2 - 1] - x[n] * R) / L;
    }

    printf("E");
    return 1;
}

void calInt(double x[div_num], double dt, double y[div_num])
{
    int i;
    double sum = 0;
    for (i = 0; i < div_num; ++i)
    {
        sum += x[i] * dt;
        y[i] = sum;
    }
}
