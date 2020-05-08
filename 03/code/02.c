#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void print_space(int col);
int print_num(int row, int size);

int main(void)
{
    int i, n, total = 0;
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        print_space(i - 1);
        total += print_num(i, n);
    }
    print_space(n);
    printf("[%4d]\n", total);
}

void print_space(int col)
{
    int i;
    for (i = 1; i <= col; ++i)
        printf("   ");
}

int print_num(int row, int size)
{
    int i;
    int sum = 0;
    for (i = 1; i <= size - row + 1; ++i)
    {
        printf(" %2d", row * row + row * (size - row + 1 - i));
        sum += row * row + row * (size - row + 1 - i);
    }

    printf(" |%4d\r\n", sum);

    return sum;
}
