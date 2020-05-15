#include <stdio.h>

int main(void)
{

    int i, count;
    double d;

    count = 0;
    for (i = 0; i < 10; i++)
    {
        count++;
        printf("i = %d\n", i);
    }

    printf("\n");

    printf("i = %d, count = %d\n", i, count);

    printf("\n\n");

    count = 0;
    for (d = 0; d < 1; d = d + 0.1)
    {
        count++;
        printf("d = %lf\n", d);
    }

    printf("\n");

    printf("d = %lf, count = %d\n", d, count);

    return 0;
}
