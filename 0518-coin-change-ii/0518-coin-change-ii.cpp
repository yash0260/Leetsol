class Solution {
public:
int f(vector<vector<int>>& dp, int n, int amount, vector<int>& coins) {

    if (amount == 0)
        return 1;

    if (n < 0)
        return 0;

    if (dp[n][amount] != -1)
        return dp[n][amount];

    int take = 0;

    if (coins[n] <= amount) {
        take = f(dp, n, amount - coins[n], coins);
    }

    int nottake = f(dp, n - 1, amount, coins);

    return dp[n][amount] = take + nottake;
}

int change(int amount, vector<int>& coins) {

    int n = coins.size();

    vector<vector<int>> dp(n, vector<int>(amount + 1, -1));

    return f(dp, n - 1, amount, coins);
}
};