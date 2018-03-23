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
using namespace std;
#define MAX_N 110

struct Node
{
    int ID;
    Node *Brother;
    Node *Child;
};

int N, M;
int maxLevel = 0;
Node *nodes[MAX_N];
int levelCnt[MAX_N];

void count(Node *root, int level)
{
    if (root == NULL)
        return;
    count(root->Child, level + 1);
    count(root->Brother, level);
    if (root->Child == NULL)
    {
        levelCnt[level]++;
        if (maxLevel <= level)
        {
            maxLevel = level;
        }
    }
}

int main()
{
    scanf("%d%d", &N, &M);
    //init nodes
    for (int i = 0; i < MAX_N; i++)
    {
        Node *node = new Node;
        node->ID = i;
        node->Brother = NULL;
        node->Child = NULL;
        nodes[i] = node;
    }
    //input
    for (int i = 0; i < M; i++)
    {
        int nodeID, childNum, childID;
        scanf("%d%d", &nodeID, &childNum);
        Node *parent = nodes[nodeID];
        for (int k = 0; k < childNum; k++)
        {
            scanf("%d", &childID);
            Node *newChild = nodes[childID];
            // first child,add to parent left
            if (k == 0)
            {
                parent->Child = newChild;
                continue;
            }
            // other child,add to child brother
            newChild->Brother = parent->Child;
            parent->Child = newChild;
        }
    }
    count(nodes[1], 0);
    for (int i = 0; i <= maxLevel; i++)
    {
        if (i != 0)
            printf(" ");
        printf("%d", levelCnt[i]);
    }
    return 0;
}
