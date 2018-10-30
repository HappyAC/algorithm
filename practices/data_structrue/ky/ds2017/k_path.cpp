#include <cstdio>
#include <iostream>
#include <fstream>
#include <stack>

struct ArcNode
{
    int weight;
    int vexIndex;
    ArcNode *next;
};

struct VexNode
{
    int index;
    char data;
    ArcNode *firstArc;
};

struct Graph
{
    int vexNum, arcNum;
    VexNode *vexNodes;
    bool *vis;
};
Graph graph;

void initVexNodes()
{
    std::ifstream indata;
    indata.open("k_path.data.in");
    int n, m;
    indata >> n;
    graph.vexNodes = new VexNode[n];
    graph.vexNum = n;
    graph.vis = new bool[n];
    for (int i = 0; i < graph.vexNum; i++)
    {
        graph.vexNodes[i].index = i;
        indata >> graph.vexNodes[i].data;
        graph.vexNodes[i].firstArc = NULL;
    }
    indata >> m;

    for (int i = 0; i < m; i++)
    {
        ArcNode *arc1 = new ArcNode;
        ArcNode *arc2 = new ArcNode;
        int from, to, weight;
        indata >> from;
        indata >> to;
        indata >> weight;
        arc1->weight = weight;
        arc2->weight = weight;
        arc1->vexIndex = to;
        arc2->vexIndex = from;

        arc1->next = graph.vexNodes[from].firstArc;
        graph.vexNodes[from].firstArc = arc1;
        arc2->next = graph.vexNodes[to].firstArc;
        graph.vexNodes[to].firstArc = arc2;

        // printf("%d %d %d \n",from,arcNode->vexIndex,arcNode->weight);
    }

    indata.close();
}

int distIndex;    // destion vex index
int pathLen;      // aim path len
int currentLen;   // current path len
bool findPath;    // find?
char paths[1000]; //paths
int  paths_top;

void dfs(Graph g, int i)
{   
    // //if only one
    // if (findPath)
    //     return;

    VexNode v = graph.vexNodes[i];
    g.vis[i] = true;
    // printf("[%d] %c len %d=> ", v.index, v.data, currentLen);

    paths[paths_top++]=v.data;
    if (distIndex == i && currentLen == pathLen)
    {
        // // if only one
        // findPath=true; 
        for(int i = 0; i < paths_top; i++)
        {
            printf("%c ",paths[i]);
        }
        printf("(%d)\nfind !\n",currentLen);
        
        g.vis[i] = false;
        paths_top--;
        return;
    }
    else
    {
        ArcNode *arc = v.firstArc;
        while (arc)
        {
            if (!g.vis[arc->vexIndex])
            {
                currentLen += arc->weight; // update len
                dfs(g, arc->vexIndex);
                currentLen -= arc->weight;
            }
            arc = arc->next;
        }
    }
    g.vis[i] = false;
    paths_top--;
}

void findKPath(Graph graph, int from, int to, int len)
{
    for (int i = 0; i < graph.vexNum; i++)
    {
        graph.vis[i] = false;
    }

    pathLen = len;
    distIndex = to;
    currentLen = 0;
    findPath = false;
    paths_top=0;    
    dfs(graph, from);
}
int main(int argc, char const *argv[])
{
    initVexNodes();
    // findKPath(graph,0,1,2);
    for (int i = 0; i < graph.vexNum; i++)
    {
        graph.vis[i] = false;
    }
    // dfs(graph,0);
    findKPath(graph, 0, 4, 10);
    return 0;
}
