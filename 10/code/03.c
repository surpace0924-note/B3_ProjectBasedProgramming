#include <stdio.h>
#include <math.h>

#define EPS .00000001

#define A -0.02
#define B -1

double func_f(double, double, double);
double func_g(double, double, double);

int main()
{
    double t = 0.0, x = 1.0, y = 1.0;
    double h = 0.005, dt = 0.2, tmax = 30.0;
    double r, ddt = 0.0;
    double b1, b2, b3, b4;
    double c1, c2, c3, c4;

    printf("%5s %10s \n", "t", "x");

    do
    {
        if (t >= ddt - EPS)
        {
            ddt += dt;
            r = 2.0 * exp(t) + exp(2.0 * t);
            printf("%10.4lf, %10.4lf\n", x, y);
        }

        b1 = func_f(t, x, y);
        c1 = func_g(t, x, y);
        b2 = func_f(t + h / 2.0, x + h * b1 / 2.0, y + h * c1 / 2.0);
        c2 = func_g(t + h / 2.0, x + h * b1 / 2.0, y + h * c1 / 2.0);
        b3 = func_f(t + h / 2.0, x + h * b2 / 2.0, y + h * c2 / 2.0);
        c3 = func_g(t + h / 2.0, x + h * b2 / 2.0, y + h * c2 / 2.0);
        b4 = func_f(t + h, x + h * b3, y + h * c3);
        c4 = func_g(t + h, x + h * b3, y + h * c3);

        x += (h / 6.0) * (b1 + 2.0 * b2 + 2.0 * b3 + b4);
        y += (h / 6.0) * (c1 + 2.0 * c2 + 2.0 * c3 + c4);
        t += h;
    } while (t <= tmax);

    return 0;
}

double func_f(double t, double x, double y)
{
    return (A * x + B * y) / sqrt(x * x + y * y);
}

double func_g(double t, double x, double y)
{
    return (A * x - B * y) / sqrt(x * x + y * y);
}
