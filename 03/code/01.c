#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void print_space(int col);
void print_num(int row, int size);

int main(void)
{
    int i, n;
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        print_space(i - 1);
        print_num(i, n);
    }

    return 0;
}

void print_space(int col)
{
    int i;
    for (i = 1; i <= col; ++i)
        printf("   ");
}

void print_num(int row, int size)
{
    int i;
    for (i = 1; i <= size - row + 1; ++i)
    {
        printf(" %2d", row * row + row * (size - row + 1 - i));
    }
    printf("\r\n");
}
