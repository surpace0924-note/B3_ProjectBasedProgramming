#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    int n;
    int i = 1;
    int j = 1;

    printf("n を入力：n = ");
    scanf("%d", &n);

    if (n >= 10)
    {
        printf("nは10未満にしてください．\r\n");
        return 0;
    }

    for (i = 1; i <= n; ++i)
    {
        // アスタリスク部分
        for (j = 1; j < i; ++j)
        {
            printf("** ");
        }

        // 九九表部分
        for (j = 0; j <= n - i; ++j)
        {
            printf("%2d ", i * (j + i));
        }

        printf("\r\n");
    }

    return 0;
}
