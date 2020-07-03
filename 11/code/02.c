#include <stdio.h>
#include <math.h>

#define END_T 2e-6
#define div_num 100 // (int)(END_T / H)
#define N 4

#define C 20e-9 / 2
#define L 2e-6 / 2
#define R 10

double func(double x[N], double t, int n);
void calInt(double x[div_num], double dt, double y[div_num]);

double init_vector[N] = {1000, 1000, 0, 0};

int main(void)
{
    int i, j;
    double t = 0;
    double h = END_T / div_num;
    double vr[div_num];
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
        vr[i] = x[i][3] * R;

    for (i = 0; i < div_num; ++i)
    {
        printf("%.10lf,%lf\r\n", (double)(h * i), vr[i]);
    }

    return 0;
}

double func(double x[N], double t, int n)
{
    switch (n)
    {
    case 0:
        return -1 * x[2] / C;
    case 1:
        return (x[3] - x[2]) / C;
    case 2:
        return (x[0] - x[1]) / L;
    case 3:
        return (x[1] - x[3] * R) / L;
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
