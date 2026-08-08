class Solution {
public:
int solve(int n, vector<int>& nums,vector<int>&dp){
    if (dp[n]!=-1)return dp[n];
if(n==0)return nums[0];
if(n==1)return max(nums[1],nums[0]);
int take=solve(n-2,nums,dp)+nums[n];
int nottake=solve(n-1,nums,dp);
return dp[n]=max(take,nottake);
}
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,-1);
        return solve(n-1,nums,dp);
    }
};