#include <stdio.h>
#include <math.h>

#define EPS .00000001

double func_f(double, double);

int main()
{
    double x = 0.0, y = 0.0;
    double h = 0.25, dx = 0.25, xmax = 5;
    double ddx = 0.0, k1, k2, k3, k4;

    printf("   X\t   Y\n");

    do
    {
        if (x >= ddx - EPS)
        {
            ddx += dx;
            printf("%8.4f, %8.4f\n", x, y);
        }

        k1 = func_f(x, y);
        k2 = func_f(x + h / 2.0, y + h * k1 * h / 2.0);
        k3 = func_f(x + h / 2.0, y + h * k2 * h / 2.0);
        k4 = func_f(x + h, y + k3 * h);

        y += (h / 6.0) * (k1 + 2.0 * k2 + 2.0 * k3 + k4);
        x += h;
    } while (x <= xmax);

    return 0;
}

double func_f(double x, double y)
{
    return -2 * x + 4 + 2 * x * sin(5 * x);
}
