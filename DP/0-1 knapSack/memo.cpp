int knapSackRec(int W, int wt[], int val[], int i, int **dp)
{
    if (i < 0)
    {
        return 0;
    }
    if (dp[i][W] != -1)
    {
        return dp[i][W];
    }
    if (wt[i] > W)
    {
        dp[i][W] = knapSackRec(W, wt, val, i - 1, dp);
    }
    else
    {
        dp[i][W] = max(val[i] + knapSackRec(W - wt[i], wt, val, i - 1, dp), knapSackRec(W, wt, val, i - 1, dp));
        return dp[i][W];
    }
}
int knapSack(int W, int wt[], int val[], int n)
{
    // Your code here
    int **dp;
    dp = new int *[n];

    for (int i = 0; i < n; i++)
    {
        dp[i] = new int[W + 1];
    }
    //int dp[n][W+1];
    //vector<vector<int>> dp(n, vector<int> (W+1, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < W + 1; j++)
        {
            dp[i][j] = -1;
        }
    }
    return knapSackRec(W, wt, val, n - 1, dp);
}