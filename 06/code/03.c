#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

#define ERROR_X 0.0001           // 許容誤差
#define ERROR_Y 0.1              // 収束判定に使用するYの許容誤差
#define MAX_INFLECTION_NUM 10000 // 保存する最大の変曲点の数（(b-a)/ERROR_Xだけ用意すれば問題ない）

// 関数の定義
double y(double);

// 二分法の計算を行う関数
double
calNibun(double a, double b);

int main(void)
{
    double a = 0.0;
    double b = 2.0;
    int i = 0;
    double tmp_x;
    double prev_y;
    int is_increase;                                    // 増加してたら1，減少なら0
    int inflection_num = 0;                             // 変曲点の数
    double inflection_list[MAX_INFLECTION_NUM] = {0.0}; // 変曲点のリスト
    double xs[MAX_INFLECTION_NUM + 1] = {0.0};          // // 求めようとするxのリスト

    printf("初期値a:%lf\n", a);
    printf("初期値b:%lf\n", b);
    printf("誤差の設定値:%lf\n", ERROR_X);

    // まずは変曲点を求める
    prev_y = y(a);
    if (y(a + ERROR_X) - prev_y > 0)
        is_increase = 1;
    else
        is_increase = 0;
    prev_y = y(a + ERROR_X);

    for (tmp_x = a + 2 * ERROR_X; tmp_x <= b; tmp_x += ERROR_X)
    {
        // 変曲点の発見
        // 増加から減少
        if (y(tmp_x) - prev_y > 0 && is_increase == 0)
        {
            inflection_list[inflection_num] = tmp_x;
            is_increase = 1;
            ++inflection_num;
        }

        // 減少から増加
        if (y(tmp_x) - prev_y < 0 && is_increase == 1)
        {
            inflection_list[inflection_num] = tmp_x;
            is_increase = 0;
            ++inflection_num;
        }
        prev_y = y(tmp_x);
    }

    // 変曲点のリストを表示
    printf("[%lf, %lf]に含まれる変曲点の数:%d\n", a, b, inflection_num);
    for (i = 0; i < inflection_num; ++i)
    {
        printf("%lf, ", inflection_list[i]);
    }

    // 解を求める
    // [a, 初めの変曲点]
    xs[0] = calNibun(a, inflection_list[0]);
    // 変曲点の間
    for (i = 0; i < inflection_num - 1; ++i)
    {
        xs[i + 1] = calNibun(inflection_list[i], inflection_list[i + 1]);
    }
    // [最後の変曲点, b]
    xs[inflection_num] = calNibun(inflection_list[inflection_num - 1], b);

    printf("\r\n\n-計算結果-\n");
    for (i = 0; i <= inflection_num; ++i)
    {
        if (fabs(y(xs[i])) < ERROR_Y)
            printf("x=%lf\tyの誤差:%lf\n", xs[i], 0 - y(xs[i]));
    }

    return 0;
}

double y(double x) //関数y=log(x)+sqrt(x) の定義
{
    return (exp(-x) * sin(10 * x + 0.5));
}

double calNibun(double a, double b)
{
    double c;
    while (1)
    {
        c = (a + b) / 2.0;

        if (y(c) * y(a) < 0)
            b = c;
        else
            a = c;

        // 収束判定
        if (fabs(a - b) < ERROR_X)
            break;
    }
    return c;
}
