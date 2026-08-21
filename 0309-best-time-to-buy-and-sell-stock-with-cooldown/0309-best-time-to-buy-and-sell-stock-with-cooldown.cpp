class Solution {
public:
    int solve(int ind, int buy, vector<int>& prices,
              vector<vector<int>>& dp) {

        // No days left
        if(ind >= prices.size())
            return 0;

        // Already calculated
        if(dp[ind][buy] != -1)
            return dp[ind][buy];

        int profit = 0;

        if(buy) {

            // Buy today
            int take = -prices[ind] +
                       solve(ind + 1, 0, prices, dp);

            // Don't buy today
            int nottake = solve(ind + 1, 1, prices, dp);

            profit = max(take, nottake);

        }
        else {

            // Sell today
            int sell = prices[ind] +
                       solve(ind + 2, 1, prices, dp);

            // Don't sell today
            int notsell = solve(ind + 1, 0, prices, dp);

            profit = max(sell, notsell);
        }

        return dp[ind][buy] = profit;
    }

    int maxProfit(vector<int>& prices) {

        int n = prices.size();

        vector<vector<int>> dp(n, vector<int>(2, -1));

        return solve(0, 1, prices, dp);
    }
};