class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {

        int n = coins.size();

        vector<vector<int>> dp(n, vector<int>(amount + 1, 0));

        // Base case: using only coins[0]
        for(int t = 0; t <= amount; t++) {

            if(t % coins[0] == 0)
                dp[0][t] = t / coins[0];
            else
                dp[0][t] = 1e9;
        }

        // Fill remaining rows
        for(int ind = 1; ind < n; ind++) {

            for(int t = 0; t <= amount; t++) {

                // Don't take current coin
                int nottake = dp[ind - 1][t];

                // Take current coin
                int take = INT_MAX;

                if(coins[ind] <= t) {
                    take = 1 + dp[ind][t - coins[ind]];
                }

                dp[ind][t] = min(take, nottake);
            }
        }

        int ans = dp[n - 1][amount];

        if(ans >= 1e9)
            return -1;

        return ans;
    }
};