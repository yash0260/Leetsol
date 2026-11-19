
class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        // If there are only 3 elements,
        // we can make all elements equal.
        if (n == 3) return 0;

        // Special case: 4 elements
        if (n == 4) {
            return min({
                nums[1] - nums[0],
                nums[2] - nums[1],
                nums[3] - nums[2]
            });
        }

        int ans = INT_MAX;

        // Case 1: Change 2 smallest elements
        ans = min(ans, nums[n - 1] - nums[2]);

        // Case 2: Change smallest and largest
        ans = min(ans, nums[n - 2] - nums[1]);

        // Case 3: Change 2 largest elements
        ans = min(ans, nums[n - 3] - nums[0]);

        return ans;
    }
};
