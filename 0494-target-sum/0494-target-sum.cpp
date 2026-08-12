class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {

        int n = nums.size();

        int total = accumulate(nums.begin(), nums.end(), 0);

        if (total - target < 0)
            return 0;

        if ((total - target) % 2 != 0)
            return 0;

        int s2 = (total - target) / 2;

        // dp[ind][sum] = number of ways to make 'sum'
        // using nums[0...ind]
        vector<vector<int>> dp(n, vector<int>(s2 + 1, 0));

        // Base case: only nums[0] is available

        if (nums[0] == 0) {
            // {} and {0}
            dp[0][0] = 2;
        }
        else {
            // Empty subset makes sum 0
            dp[0][0] = 1;

            // Taking nums[0] makes sum nums[0]
            if (nums[0] <= s2) {
                dp[0][nums[0]] = 1;
            }
        }

        // Fill the DP table
        for (int ind = 1; ind < n; ind++) {

            for (int sum = 0; sum <= s2; sum++) {

                // Don't take nums[ind]
                int notTaken = dp[ind - 1][sum];

                // Take nums[ind]
                int taken = 0;

                if (nums[ind] <= sum) {
                    taken = dp[ind - 1][sum - nums[ind]];
                }

                // Total number of ways
                dp[ind][sum] = notTaken + taken;
            }
        }

        return dp[n - 1][s2];
    }
};