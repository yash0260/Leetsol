class Solution {
    int helper(vector<int>&coins,int rem,vector<int> &dp){
        if(rem==0)return 0;
        if(rem<0)return -1;
        if(dp[rem]!=-2)return dp[rem];
        int mini=INT_MAX;
        for(int coin:coins){
            int res=helper(coins,rem-coin,dp);
            if(res>=0 && res<mini)mini=1+res;
        }
    if (mini == INT_MAX) {
    dp[rem] = -1;
} else {
    dp[rem] = mini;
}
     return dp[rem];
    }
public:
    int coinChange(vector<int>& coins, int amount) {
      vector<int>dp(amount+1,-2);
      return helper(coins,amount,dp);

    }
};