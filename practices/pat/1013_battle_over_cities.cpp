#include <cstdio>
#define N_MAX 1000

bool map[N_MAX + 2][N_MAX + 2];
bool mapVisisted[N_MAX + 2];

void dfs(int vn, int ignoreNode, int n)
{
    if (vn == ignoreNode)
        return;
    mapVisisted[vn] = true;
    for (int i = 1; i <= n; i++)
    {
        if (map[vn][i]&&!mapVisisted[i])
        {
            dfs(i, ignoreNode, n);
        }
    }
}

int calcPartNum(int ignoreNode, int n)
{
    int partNum = 0;
    for (int i = 1; i <= n; i++)
        mapVisisted[i] = false;

    for (int i = 1; i <= n; i++)
    {
        if(i==ignoreNode) continue;
        if(!mapVisisted[i]){
            partNum++;
            dfs(i,ignoreNode,n);
        }
    }
    return partNum;
}

int main()
{

    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);

    for (int i = 0; i < m; i++)
    {
        int from, to;
        scanf("%d %d", &from, &to);
        map[from][to] = true;
        map[to][from] = true;
    }

    for (int i = 0; i < k; i++)
    {
        int ignoreNode;
        scanf("%d", &ignoreNode);
        printf("%d\n", calcPartNum(ignoreNode,n)-1);
    }
    return 0;
}