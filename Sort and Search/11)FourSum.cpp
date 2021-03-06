vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    int n = nums.size();
    vector<vector<int>> ans;
    vector<int> temp = {0};
    unordered_map<int, vector<pair<int, int>>> mp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int val = target - (nums[i] + nums[j]);
            if (mp.find(val) != mp.end())
            {
                for (auto pair : mp.find(val)->second)
                {
                    int x = pair.first;
                    int y = pair.second;
                    if ((x != i && x != j) && (y != i && y != j))
                    {
                        temp = {nums[i], nums[j], nums[x], nums[y]};
                        sort(temp.begin(), temp.end());
                        ans.push_back(temp);
                    }
                }
            }
            mp[nums[i] + nums[j]].push_back({i, j});
        }
    }
    sort(ans.begin(), ans.end());
    auto it = std::unique(ans.begin(), ans.end());
    ans.resize(std::distance(ans.begin(), it));
    return ans;
}