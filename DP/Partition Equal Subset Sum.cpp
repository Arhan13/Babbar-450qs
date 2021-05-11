bool canPartition(vector<int> &nums)
{
    int sum = 0;
    for (auto x : nums)
    {
        sum += x;
    }
    if (sum % 2 != 0)
    {
        return false;
    }
    bool table[(sum / 2) + 1][nums.size() + 1];
    for (int i = 0; i <= nums.size(); i++)
    {
        table[0][i] = true;
    }
    for (int i = 1; i <= sum / 2; i++)
    {
        table[i][0] = false;
    }
    for (int i = 1; i <= sum / 2; i++)
    {
        for (int j = 1; j <= nums.size(); j++)
        {
            table[i][j] = table[i][j - 1];
            if (i >= nums[j - 1])
            {
                table[i][j] = table[i][j] || table[i - nums[j - 1]][j - 1];
            }
        }
    }
    return table[sum / 2][nums.size()];
}