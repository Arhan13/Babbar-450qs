//User function template for C++

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

class Solution
{
public:
    int height(struct Node *node)
    {
        // code here
        if (node == NULL)
        {
            return 0;
        }
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);
        if (leftHeight > rightHeight)
        {
            leftHeight += 1;
        }
        else
        {
            rightHeight += 1;
        }
        return max(leftHeight, rightHeight);
    }
};