#include <stdio.h>
#define I1 2
#define I2 3
#define I (double)(I1 + I2)

int main(void)
{

    double r;

    r = 6 / I;

    printf("r = %lf\n", r);

    return 0;
}
