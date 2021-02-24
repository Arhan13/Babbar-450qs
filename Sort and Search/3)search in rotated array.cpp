//link - https://leetcode.com/problems/search-in-rotated-sorted-array/submissions/

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        //Binary search approach
        //Finding the minimum element
        int size = nums.size();
        int low = 0;
        int high = size - 1;
        while (low < high)
        {
            int mid = (low + high) / 2;
            if (nums[mid] > nums[high])
            {
                low = mid + 1;
            }
            else
            {
                high = mid;
            }
        }
        int rotation_pos = low;
        low = 0;
        high = size - 1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            int real_mid = (mid + rotation_pos) % size;
            if (nums[real_mid] == target)
            {
                return real_mid;
            }
            else if (nums[real_mid] > target)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return -1;
    }
};