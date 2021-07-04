class Solution
{
public:
    int height(Node *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        return 1 + max(height(root->left), height(root->right));
    }
    int diameter(Node *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        int leftHeight = 0;
        int rightHeight = 0;
        leftHeight = height(root->left);
        rightHeight = height(root->right);
        int leftDiameter = diameter(root->left);
        int rightDiameter = diameter(root->right);
        return (max(leftHeight + rightHeight + 1, max(leftDiameter, rightDiameter)));
    }
};