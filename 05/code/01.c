#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    double a, b, x;
    scanf("%lf %lf", &a, &b); /* aとbの入力例 */

    if (a == 0.0)
    {
        if (b == 0.0)
        {
            printf("a and b is 0\n"); /* aとbの出力例 */
        }
        else
        {
            printf("a is 0\n"); /* aとbの出力例 */
        }
    }
    else
    {
        x = b / a;
        printf("x=%f\n", x); /* a≠0.0の場合の出力例 */
    }

    return 0;
}
