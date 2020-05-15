#define _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include <stdio.h>
#define N 20

int main(void)
{
    FILE *fp;
    int i, number[N], score[N];
    double sum = 0; // 合計
    double ave = 0; // 平均
    double var = 0; // 分散
    double dev = 0; // 標準偏差

    fp = fopen("score.txt", "rt");
    if (fp == NULL)
    {
        printf("ファイルが開けません\n");
        return 0;
    }
    for (i = 0; i < N; i++)
    {
        fscanf(fp, "%d %d", &number[i], &score[i]);
    }
    fclose(fp);

    // 平均
    for (i = 0; i < N; i++)
    {
        sum += score[i];
    }
    ave = sum / N;

    // 標準偏差
    for (i = 0; i < N; i++)
    {
        var += pow((score[i] - ave), 2.0);
    }
    var /= N;
    dev = sqrt(var);

    printf("平均：%.1f, 標準偏差：%.2f\r\n", ave, dev);
    for (i = 0; i < N; i++)
    {
        printf("受験番号：%d 偏差値：%.1f\r\n", number[i], 50 + 10 * (score[i] - ave) / dev);
    }

    return 0;
}
