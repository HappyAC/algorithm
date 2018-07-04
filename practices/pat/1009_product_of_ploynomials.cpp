// 2018-07-04 thewinds
// [题目] PAT A-1009
// 多项式乘积
// [考点] 模拟,数学
// [心得]
// 这题比较简单主要是模拟多项式的乘积
// 次数相加,相同次数的乘积求和即可
// 另外不要忽略次数为0的情况

#include <cstdio>
using namespace std;

const int N = 10 + 10;
const int N_RESULT = 2000 + 10;

float aNums[N], bNums[N], resultNums[N_RESULT];
int aPows[N], bPows[N];

int main()
{
    int m, n;
    // 输入第一个多项式
    scanf("%d", &m);
    for (int i = 0; i < m * 2; i++)
    {
        if (i % 2 == 0)
        {
            scanf("%d", &aPows[i / 2]);
        }
        else
        {
            scanf("%f", &aNums[i / 2]);
        }
    }
    // 输入第二个多项式
    scanf("%d", &n);
    for (int i = 0; i < n * 2; i++)
    {
        if (i % 2 == 0)
        {
            scanf("%d", &bPows[i / 2]);
        }
        else
        {
            scanf("%f", &bNums[i / 2]);
        }
    }

    // 计算乘积
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int nk = aPows[i] + bPows[j];
            float rn = aNums[i] * bNums[j];
            resultNums[nk] += rn;
        }
    }

    // 统计结果项数
    int cnt = 0;
    for (int i = N_RESULT - 1; i >= 0; i--)
    {
        if (resultNums[i] != 0)
        {
            cnt++;
        }
    }
    // 输出结果
    printf("%d ", cnt);
    bool isFirst = true;
    for (int i = N_RESULT - 1; i >= 0; i--)
    {
        if (resultNums[i] != 0)
        {
            if (!isFirst)
            {
                printf(" ");
            }
            isFirst = false;
            printf("%d %.1f", i, resultNums[i]);
        }
    }

    return 0;
}