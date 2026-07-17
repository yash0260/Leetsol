class Solution {
public:
long f(int ind ,int t,vector<int>&coins,vector<vector<int>>&dp){
    if(ind==0){
        return (t%coins[0]==0);
    }
    if(dp[ind][t]!=-1)return dp[ind][t];
    long nottake=f(ind-1,t,coins,dp);
    long take=0;
    if(coins[ind]<=t)take=f(ind,t-coins[ind],coins,dp);
    dp[ind][t]= take+nottake;
    return dp[ind][t];
}
    int change(int amount, vector<int>& coins) {
    int n=coins.size();
    vector<vector<int>>dp (n,vector<int>(amount+1,-1));
    return f(n-1,amount,coins,dp); 
    }
};