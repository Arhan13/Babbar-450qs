class Solution
{
public:
    bool isSubsetSum(int arr[], int n, int sum)
    {
        if (sum == 0)
        {
            return true;
        }
        if (n == 0 && sum != 0)
        {
            return false;
        }

        //if last element is greater than sum, then ignore it
        if (arr[n - 1] > sum)
        {
            return isSubsetSum(arr, n - 1, sum);
        }
        //Else check if sum can be obtained by including or excluding the last element
        return isSubsetSum(arr, n - 1, sum) || isSubsetSum(arr, n - 1, sum - arr[n - 1]);
    }

    int equalPartition(int N, int arr[])
    {
        // code here
        int sum = 0;
        for (int i = 0; i < N; i++)
        {
            sum += arr[i];
        }
        if ((sum % 2) != 0)
        {
            return false;
        }
        return isSubsetSum(arr, N, sum / 2);
    }
};