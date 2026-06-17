class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int>ans;
        vector<int>dp(n,1);
        vector<int>parent(n);
        int lastindex=0;
        int maxlen=0;
        for(int i=0;i<n;i++){
            parent[i]=i;
            for(int prevind=0;prevind<i;prevind++){
                if(nums[i]%nums[prevind]==0  && dp[i]<dp[prevind]+1){
                    dp[i]=dp[prevind]+1;
                    parent[i]=prevind;
                }
            }
            if(dp[i]>maxlen){
                lastindex=i;
                maxlen=dp[i];
            }
        }
        int i =lastindex;
        while(parent[i]!=i){
            ans.push_back(nums[i]);
            i=parent[i];
        }
        ans.push_back(nums[i]);
        return ans;
    }
};