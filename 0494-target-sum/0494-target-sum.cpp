class Solution {
    int f(int ind, int target, vector<int>& arr, vector<vector<int>>& dp){
        if(ind==0){
              if (target == 0 && arr[0] == 0)
            return 2;
              if (target == 0 || target == arr[0])
            return 1;
            return 0;
        }
         if (dp[ind][target] != -1)
        return dp[ind][target];
        
    // Calculate the number of ways without taking the current element
    int notTaken = f(ind - 1, target, arr, dp);
    
    // Calculate the number of ways by taking the current element
    int taken = 0;
    if (arr[ind] <= target)
        taken = f(ind - 1, target - arr[ind], arr, dp);
        
    // Store the sum of ways in the DP array and return it
    return dp[ind][target] = (notTaken + taken);

    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
       int total=accumulate(nums.begin(),nums.end(),0);
       if(total-target<0) return 0;
       if((total-target)%2==1) return 0;
       int s2=(total-target)/2;
       vector<vector<int>>dp(n,vector<int>(s2+1,-1));
       return f(n-1,s2,nums,dp); 
    }
};