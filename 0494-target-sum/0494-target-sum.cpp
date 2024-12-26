class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
    unordered_map<int, int> dp;
        dp[0] = 1; 

        for (int num : nums) {
            unordered_map<int, int> next_dp; 
            for (auto& entry : dp) {
                int sum = entry.first;
                int count = entry.second;
                next_dp[sum + num] += count;
                next_dp[sum - num] += count;
            }
            dp = move(next_dp);
        }

        return dp[target]; 
    }
};