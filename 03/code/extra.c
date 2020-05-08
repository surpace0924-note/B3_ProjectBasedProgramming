#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    long n;
    long i = 2;
    scanf("%ld", &n);

    while (1)
    {
        if (n % i == 0)
        {
            // nがiで割り切れる場合
            printf("%ld", i);
            n /= i;

            if (n == 1)
                return 0;

            printf("*");
        }
        else
        {
            // nがiで割り切れない場合
            ++i;
        }
    }

    return 0;
}
