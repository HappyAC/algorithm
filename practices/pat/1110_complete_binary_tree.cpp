#include <string>
#include <iostream>
#include <queue>

struct TreeNode
{
    int index, parent;
    TreeNode *left, *right;
};

using namespace std;

TreeNode *check(TreeNode *root)
{
    queue<TreeNode *> q;
    q.push(root);
    TreeNode *lastNode;
    while (!q.empty())
    {
        TreeNode *node = q.front();
        if (node == NULL)
            break;
        lastNode = node;
        q.pop();
        q.push(node->left);
        q.push(node->right);
    }
    bool allNULL = true;
    while (!q.empty())
    {
        if (q.front() != NULL)
        {
            allNULL = false;
            break;
        }
        q.pop();
    }
    if (allNULL)
    {
        return lastNode;
    }
    return NULL;
}
int main()
{
    int nodeNum;
    cin >> nodeNum;
    TreeNode *nodes = new TreeNode[nodeNum];
    for (int i = 0; i < nodeNum; i++)
    {
        TreeNode node;
        node.index = i;
        node.parent = -1;
        node.left = node.right = NULL;
        nodes[i] = node;
    }

    for (int i = 0; i < nodeNum; i++)
    {
        string lc, rc;
        cin >> lc >> rc;
        if (lc != "-")
        {
            int lcIndex = atoi(lc.c_str());
            nodes[lcIndex].parent = i;
            nodes[i].left = &nodes[lcIndex];
        }
        if (rc != "-")
        {
            int rcIndex = atoi(rc.c_str());
            nodes[rcIndex].parent = i;
            nodes[i].right = &nodes[rcIndex];
        }
    }
    TreeNode *root;
    for (int i = 0; i < nodeNum; i++)
    {
        if (nodes[i].parent == -1)
        {
            root = &nodes[i];
            break;
        }
    }
    TreeNode *lastNode = check(root);
    if (lastNode != NULL)
    {
        cout << "YES " << lastNode->index;
    }
    else
    {
        cout << "NO " << root->index;
    }

    return 0;
}