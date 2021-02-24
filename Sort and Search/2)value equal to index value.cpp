//link - https://practice.geeksforgeeks.org/problems/value-equal-to-index-value1330/1

class Solution
{
public:
    vector<int> valueEqualToIndex(int arr[], int n)
    {
        // code here
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            if ((arr[i] - 1) == i)
            {
                ans.push_back(arr[i]);
            }
        }
        return ans;
    }
};