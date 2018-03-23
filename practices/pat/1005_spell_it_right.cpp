// 2017-11-25 thewinds
// [题目] PAT A-1003
// 消防员经过最短的路径到达指定城市,问有多少条最短的路径
// 和(最短路径)最大召集的人数
// [考点] 图的遍历(dfs)
// [心得]
// 因为没有仔细审题,导致TimeOut....
// 题目中说 `Each input file contains one test case.`
// 这时候最外层就不需要用while()来不断读取了.

#include <cstdio>
#include <cstring>
using namespace std;

#define N 110

int sumNum[N];
char numStr[N];
int numStrLen;
char englishNum[10][10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

void print(int num)
{
    if (num == 0)
    {
        printf("%s", englishNum[0]);
    }
    int printNum[3] = {0}, first = 1, i = 0;
    while (num > 0)
    {
        printNum[i] = num % 10;
        num /= 10;
        i++;
    }
    for (int k = i - 1; k >= 0; k--)
    {
        if (k != i - 1)
            printf(" ");
        printf("%s", englishNum[printNum[k]]);
    }
}

void calc()
{
    memset(sumNum, 0, N);
    int sum = 0;
    for (int i = numStrLen - 1; i >= 0; i--)
    {
        int digit = numStr[i] - '0';
        // add(digit);
        sum += digit;
    }
    print(sum);
}

int main()
{
    scanf("%s", numStr);
    numStrLen = (int)strlen(numStr);
    calc();
    // printNum();
    // print();
    return 0;
}