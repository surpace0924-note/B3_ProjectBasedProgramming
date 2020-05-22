#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define N 4   // 拡大行列の行の数
#define M (N) // 拡大行列の列の数

// N行M列の行列を出力する関数
void print_p(char *s, double r[N][M]);

// 行列式の値を求める（戻り値は成功したかどうか，行列式の値はグローバル変数へ）
double det;
int cal(double p[N][M]);

int main(void)
{
    double p[N][M]; // 他の配列は使用しない
    int i, j;       // 必要に応じてint型変数定義（配列は不可）

    srand((unsigned)time(NULL));

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            p[i][j] = (double)rand() / RAND_MAX * 2.0 - 1.0;
        }
    }
    print_p("＊行列の初期値", p); // 初期データの表示

    /* 行列式の計算 */
    // まずは連立方程式を解く
    if (cal(p))
    {
        printf("＊エラー\n"); // 正常に解が得られない場合
        return 0;
    }

    /* 結果の出力 */
    printf("detA = %lf", det);

    return 0;
}

void print_p(char *s, double r[N][M])
{
    int i, j;

    printf("%s\n", s);

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < M; j++)
        {
            printf("%9.5f ", r[i][j]);
        }
        printf("\n");
    }
}

// N元連立一次方程式を解く関数（戻り値が0ならば解が求まっている）
int cal(double p[N][M])
{
    // 必要な変数の宣言（配列の新規追加は不可）
    double tmp, pivot, del, pkk, change_num; //
    int i, j, k;                             //
    pkk = 1;
    change_num = 0;

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
                    ++change_num;
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

        pkk *= pivot;
        for (j = i; j < N + 1; ++j)
        {
            p[i][j] = p[i][j] / pivot;
        }
        p[i][i] = 1.0;

        for (k = 0; k < N; ++k)
        {
            del = p[k][i];
            for (j = i; j < N + 1; ++j)
                if (k != i)
                    p[k][j] -= del * p[i][j];
        }
    }
    det = pow(-1, change_num) * pkk;
    return (0); // 正常に計算
}
