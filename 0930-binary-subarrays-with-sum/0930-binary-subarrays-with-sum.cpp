class Solution {
    int f(vector<int>&nums ,int goal){
        int l=0,r=0,ans=0,count=0;
        if(goal<0) return 0;
        for(r=0;r<nums.size();r++){
            count +=nums[r];
            while(count>goal){
                count-=nums[l];
                l++;
            }
            ans+=r-l+1;
        }
        return ans;
    }
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return f(nums,goal)-f(nums,goal-1);
    }
};