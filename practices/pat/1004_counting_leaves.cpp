#include<cstdio>
using namespace std;
#define MAX_N 110
// 2017-11-30 thewinds 
// [题目] PAT A-1004
// 统计家谱树中各个层级无后代的节点的数目
// [考点] 多叉树到二叉树的转换,输的便利
// [心得]
// -- 一开始方法不对,对于每一个节点使用一个数组来存放子节点。
// 然后用bfs进行遍历,bug巨多。。只得到部分分数。
// 正确的做法应该是把多叉树转换为二叉树，然后递归遍历，遍历的时候
// 如果是兄弟原始就传入当前层级,子元素则层级+1
// 简洁优雅 🤓 
struct Node{
    int ID;
    Node* Brother;
    Node* Child;
};

int N,M;
int maxLevel=0;
Node* nodes[MAX_N];
int levelCnt[MAX_N];

void count(Node* root,int level){
    if(root==NULL) return;
    count(root->Child,level+1);
    count(root->Brother,level);
    if(root->Child==NULL){
        levelCnt[level]++;
        if(maxLevel<=level){
            maxLevel=level;
        }
    }
}

int main(){
    scanf("%d%d",&N,&M);
    //init nodes
    for(int i=0;i<MAX_N;i++){
        Node *node=new Node;
        node->ID=i;
        node->Brother=NULL;
        node->Child=NULL;
        nodes[i]=node;
    }
    //input 
    for(int i=0;i<M;i++){
        int nodeID,childNum,childID;
        scanf("%d%d",&nodeID,&childNum);
        Node* parent=nodes[nodeID];
        for(int k=0;k<childNum;k++){
            scanf("%d",&childID);
            Node* newChild=nodes[childID];
            // first child,add to parent left
            if(k==0){
                parent->Child=newChild;
                continue;
            }
            // other child,add to child brother
            newChild->Brother=parent->Child;
            parent->Child=newChild;
        }
    }
    count(nodes[1],0);
    for(int i=0;i<=maxLevel;i++){
        if(i!=0) printf(" ");
        printf("%d",levelCnt[i]);
    }
    return 0;
}
