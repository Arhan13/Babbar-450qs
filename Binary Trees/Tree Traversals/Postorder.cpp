void postorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->left << " ";
    cout << root->right << " ";
}