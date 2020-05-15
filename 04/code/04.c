#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#define N 1001
#define E 5.0
#define C 20 * pow(10, -6)
#define R 10000

double getVolt(double t)
{
    return E * (1 - pow(M_E, -(t / (C * R))));
}

int main(void)
{
    FILE *fpd;
    int i;
    double volt;

    fpd = fopen("V-t_graph.csv", "wt");
    if (fpd == NULL)
    {
        printf("ファイルが開けません\n");
        return 0;
    }

    for (i = 0; i < N; i++)
    {
        volt = getVolt((double)i / 1000.0);
        fprintf(fpd, "%d,%4f\n", i, volt);
    }
    fclose(fpd);

    return 0;
}
