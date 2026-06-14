class Solution {
    int f(vector<int>& nums,int k){
        int n=nums.size();
        int l=0;
        int ans=0;
        unordered_map<int,int>mpp;
     
        for(int r=0;r<n;r++){
mpp[nums[r]]++;
while(mpp.size()>k){
    mpp[nums[l]]--;
    if(mpp[nums[l]]==0)mpp.erase(nums[l]);
    l++;
}
ans+=r-l+1;

        }
        return ans;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return f(nums,k)-f(nums,k-1);
    }
};