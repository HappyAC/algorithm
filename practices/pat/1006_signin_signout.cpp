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

#define MIN -1
#define MAX 1e9
struct Log
{
    char id[20];
    int hour;
    int minute;
    int second;
};

int logTimeCmp(Log a, Log b)
{
    if (a.hour == b.hour)
    {
        if (a.minute == b.minute)
        {
            if (a.second == b.second)
            {
                return 0;
            }
            return a.second > b.second ? 1 : -1;
        }
        return a.minute > b.minute ? 1 : -1;
    }
    return a.hour > b.hour ? 1 : -1;
}

int main()
{
    Log first, last, currentIn, currentOut;
    first.hour = first.minute = first.second = MAX;
    last.hour = last.minute = last.second = MIN;
    int n;
    scanf("%d", &n);
    while (n--)
    {
        scanf("%s", &currentIn.id);
        strcpy(currentOut.id, currentIn.id);
        scanf("%d:%d:%d", &currentIn.hour, &currentIn.minute, &currentIn.second);
        scanf("%d:%d:%d", &currentOut.hour, &currentOut.minute, &currentOut.second);
        if (logTimeCmp(currentIn, first) == -1)
        {
            first = currentIn;
        }
        if (logTimeCmp(currentOut, last) == 1)
        {
            last = currentOut;
        }
    }
    printf("%s %s", first.id, last.id);
    return 0;
}