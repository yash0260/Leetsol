class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();
        int maxval=INT_MIN;
        int minval=INT_MAX;
        int minidx=0;
        int maxidx=0;
        for(int i=0;i<n;i++){
           if(nums[i]<minval){
            minidx=i;
            minval=nums[i];
           }
           if(nums[i]>maxval){
            maxval=nums[i];
            maxidx=i;
           }
        }
        int k=max(minidx+1,maxidx+1);
        int l=max(n-minidx,n-maxidx);
int mixed =
            min(minidx+1, n - minidx) +
            min(maxidx + 1, n - maxidx);
        int ans=min(k,min(l,mixed));
        return ans;
    
    }
};