class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n=nums.size();
        vector<int>diff(2*limit+2,0);
        int pairs=n/2;
        int curr=pairs*2;

        for (int i=0;i<pairs;i++){
            int a=nums[i];
            int b=nums[n-1-i];
            int l=min(a,b)+1;
            int r=max(a,b)+limit;
            int sum=a+b;
            diff[l]-=1;
            diff[r+1]+=1;
            diff[sum]-=1;
            diff[sum+1]+=1;
        }
        int ans=INT_MAX;
        for(int s=2;s<=2*limit;s++){
            curr+=diff[s];
            ans=min(ans,curr);
        }
        return ans;
    }
};