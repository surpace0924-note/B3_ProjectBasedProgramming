#include <stdio.h>
void print_p(void);
void print_px(void);
#define N 2
// double p[N][N + 1] = {{0.0, 2.0, 3.0},
//                       {2.0, 3.0, 4.0}};

// double p[N][N + 1] = {{2.0, 3.0, 4.0},
//                       {4.0, 6.0, 8.0}};

double p[N][N + 1] = {{2.0, 3.0, 4.0},
                      {4.0, 6.0, 10.0}};

int main()
{
    int i;      /* 必要ならば実数変数の宣言 */
    double tmp; /* 必要ならば整数変数の宣言 */
    print_px(); /* 与えられた連立方程式を表示 */

    /* ここに，行列の操作を記述する */
    // step2
    if (p[0][0] == 0 && p[1][0] == 0)
    {
        printf("解なし\r\n");
    }

    if (p[0][0] == 0)
    {
        for (i = 0; i < N + 1; ++i)
        {
            tmp = p[0][i];
            p[0][i] = p[1][i];
            p[1][i] = tmp;
        }
    }

    tmp = p[0][0];
    for (i = 0; i < N + 1; ++i)
    {
        p[0][i] /= tmp;
    }
    p[0][0] = 1.0;

    // step3
    tmp = p[1][0];
    if (p[1][0] != 0.0)
    {
        for (i = 0; i < N + 1; ++i)
        {
            p[1][i] -= p[0][i] * tmp;
        }
    }
    p[1][0] = 0.0;

    // step4
    if (p[1][1] != 0)
    {
        p[1][2] /= p[1][1];
        p[1][1] = 1.0;
    }
    else
    {
        if (p[1][2] == 0)
        {
            printf("解は不定\r\n");
        }
        else
        {
            printf("解なし\r\n");
        }
        return 0;
    }

    // step5
    if (p[0][1] != 0)
    {
        p[0][2] -= p[0][1] * p[1][2];
        p[0][1] = 0;
    }

    printf("x0=%lf, x1=%lf\n", p[0][2], p[1][2]); /* 解の表示 */

    return 0;
}

void print_p(void)
{
    int i, j;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N + 1; j++)
        {
            printf("%lf ", p[i][j]);
        }
        printf("\n");
    }
    printf("-----------------------------------\n");
}

void print_px(void)
{
    int i, j;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            printf("%lf * x%1d ", p[i][j], j);
            if (j < N - 1)
                printf("+");
        }
        printf("= %lf\n", p[i][N]);
    }
    printf("-----------------------------------\n");
}
