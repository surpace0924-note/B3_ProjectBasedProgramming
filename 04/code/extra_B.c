#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define N1 20     // スコア1の人数
#define N2 20     // スコア2の人数
#define N N1 + N2 // 全体の人数

// 2つの配列をaを基準に降順にソートする関数
void sortArray(int a[], int b[], int len);

int main(void)
{
    FILE *fp1, *fp2, *fpo;
    int i, j, number_all[N], score_all[N];
    int dup_num = 0;         // ある点数が重複している数
    int number_sub[N] = {0}; // 重複している要素だけをまとめる配列
    int score_sub[N] = {0};  // 重複している要素だけをまとめる配列

    // ファイルオープン
    fp1 = fopen("score1.txt", "rt");
    fp2 = fopen("score2.txt", "rt");
    fpo = fopen("output.csv", "wt");
    if (fp1 == NULL || fp2 == NULL || fpo == NULL)
    {
        printf("ファイルが開けません\n");
        return 0;
    }

    // ファイルの中身を読む
    for (i = 0; i < N1; i++)
        fscanf(fp1, "%d %d", &number_all[i], &score_all[i]);
    for (i = 0; i < N2; i++)
        fscanf(fp2, "%d %d", &number_all[N1 + i], &score_all[N1 + i]);

    // ファイルクローズ
    fclose(fp1);
    fclose(fp2);

    // スコア順にソートする（受験番号も対応するように入れ替えられる）
    sortArray(score_all, number_all, N);

    // 点数の重複箇所を検出
    for (i = 0; i < N - 1; ++i)
    {
        // 重複の発見
        if (score_all[i] == score_all[i + 1])
        {
            // この点数の重複がいくつあるのかを調査
            dup_num = 0;
            for (j = i; j < N; ++j)
            {
                if (score_all[i] != score_all[j])
                    break;
                dup_num++;
            }

            // 重複しているものだけを抜き出して配列化
            for (j = 0; j < dup_num; ++j)
            {
                number_sub[j] = number_all[i + j];
                score_sub[j] = score_all[i + j];
            }

            // 今度は受験番号順にソート
            sortArray(number_sub, score_sub, N);

            // ソートした重複配列を元の配列に戻す
            for (j = 0; j < dup_num; ++j)
            {
                number_all[i + j] = number_sub[j];
                score_all[i + j] = score_sub[j];
            }

            // 次ループに影響が出ないように重複配列を初期化
            for (j = 0; j < dup_num; ++j)
            {
                number_sub[j] = 0;
                score_sub[j] = 0;
            }

            // 計算量を減らすため，すでに探索が終了したところは次ループでは検索しない
            i += dup_num - 1;
        }
    }

    // ファイル出力
    for (i = 0; i < N; ++i)
        fprintf(fpo, "%d,%d\n", number_all[i], score_all[i]);

    // ファイルクローズ
    fclose(fpo);

    return 0;
}

// 2つの配列をaを基準に降順にソートする関数
void sortArray(int a[], int b[], int len)
{
    int ins, cmp, temp_a, temp_b;
    for (ins = 1; ins < len; ins++)
    {
        temp_a = a[ins];
        temp_b = b[ins];
        for (cmp = ins - 1; cmp >= 0; cmp--)
        {
            if (a[cmp] < temp_a)
            {
                a[cmp + 1] = a[cmp];
                b[cmp + 1] = b[cmp];
            }
            else
            {
                break;
            }
        }
        a[cmp + 1] = temp_a;
        b[cmp + 1] = temp_b;
    }
}
