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
    printf("pre oreder recursion: ");
    preOrder(root);
    printf("\n");
    printf("pre oreder non-recursion: ");
    std::stack<TreeNode*> nodes;
    nodes.push(root);
    
    while(!nodes.empty()){
        TreeNode *cur = nodes.top();
        nodes.pop();
        if (cur!=NULL) {
            printf("%c ",cur->data);
            nodes.push(cur->right);
            nodes.push(cur->left);
        } 
    }
    printf("\n");
    
}
void Tree::InOrder(){
    printf("in oreder recursion: ");
    inOrder(root);
    printf("\n");
    printf("in oreder non-recursion: ");
    
    std::stack<TreeNode*> nodes;
    TreeNode *pre = new TreeNode;
    nodes.push(root);

    //  M
    // L R  R=>M=>L
    while(!nodes.empty()){
        TreeNode *cur = nodes.top();
        nodes.pop();

        if(cur==NULL){
            pre=cur;
            continue;
        }
        
        if (cur->left==pre||cur->right==pre) {
            printf("%c ",cur->data);
            pre=cur;
            continue;
        }
            
        nodes.push(cur->right);
        nodes.push(cur);
        nodes.push(cur->left);
        pre=cur;
    }

    printf("\n");
    

}
void Tree::PostOrder(){
    printf("post oreder recursion: ");
    postOrder(root);
    printf("\n");
    printf("post oreder non-recursion: ");

    std::stack<TreeNode*> nodes;
    nodes.push(root);
    TreeNode *pre = new TreeNode;
    while(!nodes.empty()){
        TreeNode *cur = nodes.top();
        if(cur==NULL){
            pre=NULL;
            nodes.pop();
            continue;
        }
        if((pre==cur->left&&cur->right==NULL)
            ||pre==cur->right){
            printf("%c ",cur->data);
            nodes.pop();
        }else{
            nodes.push(cur->right);
            nodes.push(cur->left);
        }
        pre=cur;

    }
    printf("\n");

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
    printf("%c ",node->data);  
    preOrder(node->left);
    preOrder(node->right);
}
void Tree::inOrder(TreeNode *node){
    if(node==NULL) return;
    inOrder(node->left);
    printf("%c ",node->data);  
    inOrder(node->right);
}
void Tree::postOrder(TreeNode *node){
    if(node==NULL) return;
    postOrder(node->left);
    postOrder(node->right);
    printf("%c ",node->data);  
    
}

void Tree::LevelOrder(){
    std::queue<TreeNode*> nodes;
    nodes.push(root);
    while(!nodes.empty()){
        TreeNode* node = nodes.front();
        nodes.pop();
        printf("%c ",node->data);
        if(node->left!=NULL) nodes.push(node->left);
        if(node->right!=NULL) nodes.push(node->right);
    }
    printf("\n");
}

int countTreeDeep(Tree tree){
    int maxDeep=0,deep = 0;
    std::stack<TreeNode*> nodes;
    nodes.push(tree.root);
    while(!nodes.empty()){
        TreeNode *cur = nodes.top();
        nodes.pop();
        if(cur!=NULL){
            printf("%c",cur->data);
            nodes.push(cur->right);
            nodes.push(cur->left);
            if(cur->left!=NULL||cur->right!=NULL){
                maxDeep++;
            }
        }
    }
    printf("\n");
    return maxDeep;
}

int main(int argc, char const *argv[])
{
    Tree tree;
    char str[]="1246####3#5##";
    // char str[]="1##";
    tree.Assgin(str);
    tree.PreOrder();
    tree.InOrder();
    tree.PostOrder();
    tree.LevelOrder();
    //printf("deep: %d",countTreeDeep(tree));
    return 0;
}