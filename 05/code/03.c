// Gauss-Jordan method

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define N 5       // 拡大行列の行の数
#define M (N + 1) // 拡大行列の列の数
#define L 2       // 初期行列操作用

// N行M列の行列を出力する関数
void print_p(char *s, double r[N][M]);

// N元連立一次方程式を解く関数
int mat_leq(double p[N][M]);

double x[] = {-1.6, 2.7, 3.8, 4.1, 5.5};
int main(void)
{
    double p[N][M];
    int i, j;

    srand((unsigned)time(NULL));

    for (i = 0; i < N; i++)
    {
        p[i][N] = 0.0;
        for (j = 0; j < N; j++)
        {
            if (i > L || j > L - 1)
            {
                p[i][j] = (double)rand() / RAND_MAX * 2.0 - 1.0;
                p[i][N] += p[i][j] * x[j];
            }
            else
            {
                p[i][j] = 0.0;
            }
        }
    }

    print_p("＊拡大行列の初期値", p); // 初期データの表示

    if (mat_leq(p))
    {
        printf("＊エラー\n"); // 正常に解が得られない場合
        return 0;
    }

    print_p("＊掃き出し後の値", p); // 掃き出し後の表示

    printf("＊結果\n");
    for (i = 0; i < N; i++)
        printf("%16.8e\n", p[i][N]);

    return 0; // 正常終了
}

// N元連立一次方程式を解く関数（戻り値が0ならば解が求まっている）
int mat_leq(double p[N][M])
{
    // 必要な変数の宣言（配列の新規追加は不可）
    double tmp, pivot, del; //
    int i, j, k;            //

    for (i = 0; i < N; i++)
    {
        // 1行目からN行目まで

        // 小行列の左上が0の時は以降の要素をみて入れ替えを行う
        if (p[i][i] == 0)
        {
            for (j = i; j < N; ++j)
            {
                if (p[j][i] != 0)
                {
                    for (k = 0; k < M; ++k)
                    {
                        tmp = p[i][k];
                        p[i][k] = p[j][k];
                        p[j][k] = tmp;
                    }
                }
            }
        }

        // 小行列の左上をピボットとする
        // この時，ピボットが0の時は解なしとして返す
        pivot = p[i][i];
        if (pivot == 0.0)
        {
            return 1;
        }

        for (j = i; j < N + 1; ++j)
            p[i][j] = p[i][j] / pivot;
        p[i][i] = 1.0;

        for (j = 0; j < N; ++j)
        {
            del = p[j][i];
            for (k = i; k < N + 1; ++k)
                if (j != i)
                    p[j][k] -= del * p[i][k];
            p[j][i] = 0.0;
        }

        print_p("＊途中結果", p);
    }

    return (0); // 正常に計算
}

void print_p(char *s, double r[N][M])
{
    int i, j;

    printf("%s\n", s);

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < M; j++)
            printf("%9.5f ", r[i][j]);
        printf("\n");
    }
}
