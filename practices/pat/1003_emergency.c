// 2017-11-25 thewinds
// [题目] PAT A-1003
// 消防员经过最短的路径到达指定城市,问有多少条最短的路径
// 和(最短路径)最大召集的人数
// [考点] 图的遍历(dfs)
// [心得]
// 因为没有仔细审题,导致TimeOut....
// 题目中说 `Each input file contains one test case.`
// 这时候最外层就不需要用while()来不断读取了.
#include <stdio.h>
#include <string.h>
#define N 500 + 10

int roads[N][N];
int visit[N];
int teamNums[N];

int peoples, roadDistance;
int maxPeoples, minRoadDistance;
int sCnt;
void dfs(int n, int start, int end)
{
    if (start == end)
    {
        // printf("\n");
        // printf("find: distance %d,peoples %d\n",roadDistance,peoples+teamNums[end]);
        peoples += teamNums[end];
        if (roadDistance < minRoadDistance)
        {
            minRoadDistance = roadDistance;
            maxPeoples = peoples;
            sCnt = 0;
        }
        if (roadDistance == minRoadDistance)
        {
            if (peoples > maxPeoples)
            {
                maxPeoples = peoples;
            }
            sCnt++;
        }
        peoples -= teamNums[end];
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (roads[start][i] != -1 && !visit[i])
        {
            roadDistance += roads[start][i];
            visit[i] = 1;
            peoples += teamNums[start];
            dfs(n, i, end);
            peoples -= teamNums[start];
            roadDistance -= roads[start][i];
            visit[i] = 0;
        }
    }
}

int main()
{
    // n citys
    // m roads
    int n, m, start, end;
    scanf("%d%d%d%d", &n, &m, &start, &end);
    int nn = n, mm = m;
    minRoadDistance = 1e9;
    maxPeoples = -1;
    memset(roads, -1, sizeof(roads));
    memset(visit, 0, sizeof(visit));
    memset(teamNums, 0, sizeof(teamNums));
    while (nn)
    {
        scanf("%d", &teamNums[n - nn]);
        nn--;
    }
    while (mm--)
    {
        int from, to, distance;
        scanf("%d%d%d", &from, &to, &distance);
        roads[from][to] = distance;
        roads[to][from] = distance;
    }
    dfs(n, start, end);
    printf("%d %d\n", sCnt, maxPeoples);

    return 0;
}