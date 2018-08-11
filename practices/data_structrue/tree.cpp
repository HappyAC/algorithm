#include <cstdio>
#include <queue>
#include <stack>
#include <cstring>

#define DataType char

struct TreeNode
{
    DataType data;
    TreeNode *left;
    TreeNode *right;
};

struct Tree
{
    TreeNode *root;

  public:
    void Assgin(char *str);
    void PreOrder();
    void InOrder();
    void PostOrder();
    void LevelOrder();

  private:
    void assgin(TreeNode *&node,char *&str);
    void preOrder(TreeNode *node);
    void inOrder(TreeNode *node);
    void postOrder(TreeNode *node);
};

void Tree::Assgin(char* str){
    //        1
    //     2     3
    //   4   #  #  5
    // #  #      #   #
    // 124###3#5##
    if(root!=NULL) return;
    assgin(root,str);
}
void Tree::PreOrder(){
    preOrder(root);
    printf("\n");
}
void Tree::InOrder(){
    inOrder(root);
    printf("\n");
}
void Tree::PostOrder(){
    printf("recursion: ");
    postOrder(root);
    printf("\n");
    printf("non-recursion: ");
    //        1
    //     2     3
    //   4   #  6  5
    // #  #      #   #

    // s1 1 2 4
    // s2 1 3 5 6 2 4

    std::stack<TreeNode*> nodes;
    nodes.push(root);
    TreeNode *pre = NULL;
    while(!nodes.empty()){
        TreeNode *node = nodes.top();
        if(node->left==NULL&&node->right==NULL){
            pre=node;
            printf("%c",node->data);
            nodes.pop();
            continue;
        }

        if(pre==node->left){
            nodes.push(node->right);
            pre=node;
            continue;
        }
        
        if(pre==node->right){
            pre=node;
            printf("%c",node->data);
            nodes.pop();
        }
    }
}
void Tree::assgin(TreeNode *&node,char *&str){
    if(strlen(str)==0) return;
    if(str[0]=='#'){
        str++;
        return;
    }
    node = new TreeNode;
    node->left=NULL;
    node->right=NULL;
    node->data=str[0];
    str++;
    assgin(node->left,str);
    assgin(node->right,str);
}

void Tree::preOrder(TreeNode *node){
    if(node==NULL) return;
    printf("%c",node->data);  
    preOrder(node->left);
    preOrder(node->right);
}
void Tree::inOrder(TreeNode *node){
    if(node==NULL) return;
    inOrder(node->left);
    printf("%c",node->data);  
    inOrder(node->right);
}
void Tree::postOrder(TreeNode *node){
    if(node==NULL) return;
    postOrder(node->left);
    postOrder(node->right);
    printf("%c",node->data);  
    
}

void Tree::LevelOrder(){
    std::queue<TreeNode*> nodes;
    nodes.push(root);
    while(!nodes.empty()){
        TreeNode* node = nodes.front();
        nodes.pop();
        printf("%c",node->data);
        if(node->left!=NULL) nodes.push(node->left);
        if(node->right!=NULL) nodes.push(node->right);
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
    Tree tree;
    char str[]="124###3#5##";
    tree.Assgin(str);
    tree.PreOrder();
    tree.InOrder();
    tree.PostOrder();
    tree.LevelOrder();
    return 0;
}
