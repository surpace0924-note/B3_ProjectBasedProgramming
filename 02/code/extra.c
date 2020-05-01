#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void ban_print(int sanmoku1[5][5])
{
    int j, k;
    for (k = 0; k < 5; k++)
    {
        for (j = 0; j < 5; j++)
        {
            if (sanmoku1[k][j] == -1)
            {
                printf("■");
            }
            else if (sanmoku1[k][j] == 0)
            {
                printf("・");
            }
            else if (sanmoku1[k][j] == 3)
            {
                printf("○");
            }
            else if (sanmoku1[k][j] == 5)
            {
                printf("×");
            }
        }
        printf("\r\n");
    }
}

// 勝敗がついたかどうか
int isEnd(int sanmoku1[5][5])
{
    int i;

    // 縦横の判定
    for (i = 1; i <= 3; i++)
    {
        if (sanmoku1[1][i] != 0 && sanmoku1[1][i] == sanmoku1[2][i] && sanmoku1[2][i] == sanmoku1[3][i])
            return 1;
        if (sanmoku1[i][1] != 0 && sanmoku1[i][1] == sanmoku1[i][2] && sanmoku1[i][2] == sanmoku1[i][3])
            return 1;
    }

    // 斜めの判定
    if (sanmoku1[i][1] != 0 && sanmoku1[1][1] == sanmoku1[2][2] && sanmoku1[2][2] == sanmoku1[3][3])
        return 1;
    if (sanmoku1[3][1] != 0 && sanmoku1[3][1] == sanmoku1[2][2] && sanmoku1[2][2] == sanmoku1[1][3])
        return 1;

    return 0;
}

int main()
{
    int sanmoku[5][5] = {
        {-1, -1, -1, -1, -1},
        {-1, 0, 0, 0, -1},
        {-1, 0, 0, 0, -1},
        {-1, 0, 0, 0, -1},
        {-1, -1, -1, -1, -1},
    };
    int i, a, b;
    int can_next = 0;

    ban_print(sanmoku);

    for (i = 0; i < 9; i++)
    {
        printf("\r\n");
        if (i % 2 == 0)
        {
            can_next = 0;
            do
            {
                printf("先攻：x y =");
                scanf("%d %d", &a, &b);
                if (sanmoku[b][a] == 0 && sanmoku[b][a] != -1 && a <= 3 && b <= 3)
                {
                    sanmoku[b][a] = 3;
                    can_next = 1;
                }
            } while (can_next == 0);
        }
        else
        {
            can_next = 0;
            do
            {
                printf("後攻：x y =");
                scanf("%d %d", &a, &b);
                if (sanmoku[b][a] == 0 && sanmoku[b][a] != -1 && a <= 3 && b <= 3)
                {
                    sanmoku[b][a] = 5;
                    can_next = 1;
                }
            } while (can_next == 0);
        }

        // 盤面を表示
        ban_print(sanmoku);

        // 終了判定
        if (isEnd(sanmoku))
        {
            if (i % 2 == 0)
                printf("先攻の勝ちです\r\n");
            else
                printf("後攻の勝ちです\r\n");

            return 0;
        }
    }

    printf("引き分けです\r\n");

    return 0;
}
