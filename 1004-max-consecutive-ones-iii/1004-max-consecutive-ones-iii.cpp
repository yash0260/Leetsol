class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int one=0;
        int zero=0;
        int n=nums.size();
        int l=0;
        int ans=INT_MIN;
        for(int r=0;r<n;r++){
if(nums[r]==1){
one++;
        }else{
        zero++;
    }
     while(zero>k){
            if(nums[l]==0){
            zero--;
            }
            l++;
            }
    ans=max(ans,r-l+1);

        }
        return ans;

    }
};