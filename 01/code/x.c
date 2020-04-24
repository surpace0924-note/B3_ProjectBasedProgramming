#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define N 3 // 入力する自然数の個数

// 最大公約数
int gcd(int a, int b)
{
    return b ? gcd(b, a - (a / b) * b) : a;
}

// 最小公倍数
int lcm(int a, int b)
{
    return a * b / gcd(a, b);
}

int main(void)
{
    int n[N];
    int i;
    int ans;

    // 入力受付
    printf("%dつの自然数を入力：\r\n", N);
    for (i = 0; i < N; ++i)
    {
        printf("n[%d] = ", i);
        scanf("%d", &n[i]);

        // ガード
        if (n[i] < 0)
        {
            printf("自然数を入力してください．\r\n");
            return 0;
        }
    }

    // 前回の最小公倍数の値と今回の要素との最小公倍数を求め続ける
    ans = n[0];
    for (i = 1; i < N; ++i)
    {
        ans = lcm(ans, n[i]);
    }

    printf("lcm: %d ", ans);
    return 0;
}
