#include <stdio.h>
#include <math.h>

#define EPS .00000001

double func_f(double);

int main()
{
    double x = 0.0, y = 0.0;
    double h = 0.0625, dx = 0.0625, xmax = 5;
    double ddx = 0.0;

    printf("   X\t   Y\n");

    do
    {
        if (x >= ddx - EPS)
        {
            ddx += dx;
            printf("%7.4f, %7.4f\n", x, y);
        }

        y += h * func_f(x);
        x += h;
    } while (x <= xmax);

    return 0;
}

double func_f(double x)
{
    return -2 * x + 4 + 2 * x * sin(5 * x);
}
