class Solution {
public:
int f(int n, vector<int>& nums,vector<int>&dp){
    if (dp[n]!=-1)return dp[n];
if(n==0)return nums[0];
if(n==1)return max(nums[1],nums[0]);
int take=f(n-2,nums,dp)+nums[n];
int nottake=f(n-1,nums,dp);
return dp[n]=max(take,nottake);
}
    int robLinear(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,-1);
        return f(n-1,nums,dp);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0]; 

        vector<int> temp1, temp2;
        
        for (int i = 1; i < n; i++) temp1.push_back(nums[i]);
        
        for (int i = 0; i < n - 1; i++) temp2.push_back(nums[i]);

        return max(robLinear(temp1), robLinear(temp2));
    }
};