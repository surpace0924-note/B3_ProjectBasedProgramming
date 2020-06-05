#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

#define N 20        // データ点数（変更しないこと）
#define xmin (-2.0) // （変更しないこと）
#define xmax (2.0)  // （変更しないこと）
#define L 100       // 全区間の分割数（きちんと"補間"がされてさえすれば変数名ごと変更してもよい）
#define MAX_ORDER 4 // 補間時の最大の次数

int findNearPointIndex(double x[N], double a);
double calLagrange(double sub_x[MAX_ORDER], double sub_y[MAX_ORDER], double a);

int main()
{
    int i, k;
    int near_point;
    double a, sum;
    double x[N];
    double y[N];
    double sub_x[MAX_ORDER], sub_y[MAX_ORDER];
    FILE *fp;

    if ((fp = fopen("output3_1.csv", "w")) == NULL)
    {
        printf("出力用ファイル開けず\n");
        return (1);
    }

    /* データ点の準備（変更しないこと）*/
    for (i = 0; i < N; i++)
    {
        x[i] = xmin + i * (xmax - xmin) / (N - 1.0);
        y[i] = 1.0 / (36.0 * x[i] * x[i] + 1.0);
    }

    /* 補間計算（ここを完成させる。大幅に書き換えても良いが、x[i]やy[i]に適当な変換を施したものに対して補間を行い、その結果を逆変換するというのはダメ。）*/
    for (k = 0; k < L + 1; k++)
    {
        a = x[0] + k * (x[N - 1] - x[0]) / L;

        // aに一番近いxを求める
        near_point = findNearPointIndex(x, a);

        // インデックス内に抑える
        if (near_point - MAX_ORDER / 2 < 0)
            near_point = MAX_ORDER / 2;
        if (near_point + MAX_ORDER / 2 + 1 > N)
            near_point = N - MAX_ORDER / 2 - 1;

        // aに近いMAX_ORDER点だけの点群配列を作成
        for (i = 0; i < MAX_ORDER; i++)
        {
            sub_x[i] = x[near_point - MAX_ORDER / 2 + i];
            sub_y[i] = y[near_point - MAX_ORDER / 2 + i];
        }
        sum = calLagrange(sub_x, sub_y, a);

        near_point++;
        // インデックス内に抑える
        if (near_point - MAX_ORDER / 2 < 0)
            near_point = MAX_ORDER / 2;
        if (near_point + MAX_ORDER / 2 + 1 > N)
            near_point = N - MAX_ORDER / 2 - 1;
        // aに近いMAX_ORDER点だけの点群配列を作成
        for (i = 0; i < MAX_ORDER; i++)
        {
            sub_x[i] = x[near_point - MAX_ORDER / 2 + i];
            sub_y[i] = y[near_point - MAX_ORDER / 2 + i];
        }

        sum += calLagrange(sub_x, sub_y, a);

        fprintf(fp, "%lf, %lf\n", a, sum / 2);
    }

    fclose(fp);
    return 0;
}

int findNearPointIndex(double x[N], double a)
{
    int i;
    double dx = fabs(x[N - 1] - x[0]);
    double min_i = 0;
    for (i = 0; i < N; i++)
    {
        if (dx > fabs(a - x[i]))
        {
            dx = fabs(a - x[i]);
            min_i = i;
        }
    }
    return min_i;
}

double calLagrange(double sub_x[MAX_ORDER], double sub_y[MAX_ORDER], double a)
{
    int i, j;
    double tmp, sum;
    sum = 0;

    for (i = 0; i < MAX_ORDER; i++)
    {
        tmp = 1.0;
        for (j = 0; j < MAX_ORDER; j++)
        {
            if (i != j)
                tmp *= (a - sub_x[j]) / (sub_x[i] - sub_x[j]);
        }
        sum += sub_y[i] * tmp;
    }

    return sum;
}
