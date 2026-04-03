class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums) {
        int n=nums.size();
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                for(int j=i+1;j<n;j++){
                    if(nums[j]==2){
                        ans=min(ans,abs(j-i));
                    }
                }
            }
        }
        for(int i=n-1;i>=0;i--){
            if(nums[i]==1){
                for(int j=i-1;j>=0;j--){
                    if(nums[j]==2){
                        ans=min(ans,abs(j-i));
                    }
                }
            }
        }
        if(ans<INT_MAX){
            return ans;
        }else{
            return -1;
        }
    }
};