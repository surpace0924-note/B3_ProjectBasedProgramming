#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define N 4
#define M 5

// N行M列の行列を出力する関数
void print_matrix(char *s, int n, int m, double r[n][m]);

// 行列式の値を求める（戻り値は成功したかどうか，行列式の値はグローバル変数へ）
double det;
int cal(double p[M][N]);

// 転置（転置後の行列はグローバル変数へ）
void transposition(double p[M][N]);
double A_t[N][M];

// 掛け算
void multiplication(int Na1, int Na2, int Nb2, double a[Na1][Na2], double b[Na2][Nb2], double ans[Na1][Nb2]);

// 逆行列（計算結果の行列はグローバル変数へ）
void inverse(int n, double a[n][n]);
double A_inverse[N][N];

int main(void)
{
    double A[M][N];
    double A_square[N][N];
    double A_pseudo_inverse[N][M];
    double b[M][1];
    double ans[N][1];
    int i, j;
    srand((unsigned)time(NULL));

    for (i = 0; i < M; i++)
    {
        for (j = 0; j < N; j++)
        {
            A[i][j] = (double)rand() / RAND_MAX * 2.0 - 1.0;
        }
        b[i][0] = (double)rand() / RAND_MAX * 2.0 - 1.0;
    }

    print_matrix("＊行列Aの初期値", M, N, A);
    print_matrix("\r\n＊ベクトルbの初期値", M, 1, b);

    transposition(A);

    multiplication(N, M, N, A_t, A, A_square);

    inverse(N, A_square);

    multiplication(N, N, M, A_inverse, A_t, A_pseudo_inverse);

    multiplication(N, M, 1, A_pseudo_inverse, b, ans);
    print_matrix("\r\n-ans-", N, 1, ans);

    return 0;
}

void print_matrix(char *s, int n, int m, double r[n][m])
{
    int i, j;

    printf("%s\n", s);

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("%9.5f ", r[i][j]);
        }
        printf("\n");
    }
}

// 転置
void transposition(double A[M][N])
{
    int i, j;
    for (i = 0; i < M; ++i)
    {
        for (j = 0; j < N; ++j)
        {
            A_t[j][i] = A[i][j];
        }
    }
}

void multiplication(int Na1, int Na2, int Nb2, double a[Na1][Na2], double b[Na2][Nb2], double ans[Na1][Nb2])
{
    int i, j, k;
    for (i = 0; i < Na1; i++)
    {
        for (j = 0; j < Na2; j++)
        {
            for (k = 0; k < Nb2; k++)
            {
                ans[i][k] += a[i][j] * b[j][k];
            }
        }
    }
}

void inverse(int n, double a[n][n])
{
    double buf;  //一時的なデータを蓄える
    int i, j, k; //カウンタ

    //単位行列を作る
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            A_inverse[i][j] = (i == j) ? 1.0 : 0.0;
        }
    }
    //掃き出し法
    for (i = 0; i < n; i++)
    {
        buf = 1 / a[i][i];
        for (j = 0; j < n; j++)
        {
            a[i][j] *= buf;
            A_inverse[i][j] *= buf;
        }
        for (j = 0; j < n; j++)
        {
            if (i != j)
            {
                buf = a[j][i];
                for (k = 0; k < n; k++)
                {
                    a[j][k] -= a[i][k] * buf;
                    A_inverse[j][k] -= A_inverse[i][k] * buf;
                }
            }
        }
    }
}
