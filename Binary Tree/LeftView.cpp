/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

void dfs(Node *root, int level, vector<int> &ans)
{
    if (root == NULL)
    {
        return;
    }
    if (level >= ans.size())
    {
        ans.push_back(root->data);
    }
    dfs(root->left, level + 1, ans);
    dfs(root->right, level + 1, ans);
}

// // A wrapper over leftViewUtil()
// vector<int> leftView(Node *root)
// {
//     // Your code here
//     int max_level = 0;
//     vector<int> ans;
//     dfs(root, max_level, ans);
//     return ans;
// }