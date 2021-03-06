/* A binary tree node has data, pointer to left child
   and a pointer to right child 
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

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
    dfs(root->right, level + 1, ans);
    dfs(root->left, level + 1, ans);
}

// Should return  right view of tree
vector<int> rightView(Node *root)
{
    // Your Code here
    vector<int> ans;
    dfs(root, 0, ans);
    return ans;
}