class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
       int n=nums.size();
       int ans=INT_MAX;
       for(int i=0;i<n;i++){
        int c=INT_MAX;
        if(nums[i]==target){
            c=abs(i-start);
        }
ans=min(ans,c);
       } 
       return ans;
    }
};