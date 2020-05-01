/* 乱数の生成_サンプルプログラム */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 100

int main(void)
{
    int i, j, tokuten[N] = {0};
    int kaikyu[11] = {0};

    srand((unsigned)time(NULL));
    for (i = 0; i < N; i++)
    {
        tokuten[i] = (rand() % 101);
        printf("%4d", tokuten[i]);
    }
    printf("\r\n");

    // 階級値の算出
    for (i = 0; i < N; ++i)
        ++kaikyu[tokuten[i] / 10];

    // 描画
    printf("   階級     度数\r\n");
    for (i = 0; i < 10; ++i)
    {
        printf("%3d 〜 %2d %2d：", 10 * i, 10 * i + 9, kaikyu[i]);

        for (j = 0; j < kaikyu[i]; ++j)
            printf("*");

        printf("\r\n");
    }

    // 100だけ表示方法が違うので別で処理
    printf("%3d       %2d：", 100, kaikyu[10]);
    for (j = 0; j < kaikyu[10]; ++j)
        printf("*");

    printf("\r\n");
}
