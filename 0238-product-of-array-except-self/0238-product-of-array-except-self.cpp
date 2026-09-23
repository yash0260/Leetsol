class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        int ans=1;
int cnt=0;
int k=1;
        for(int i=0;i<n;i++){
            ans=nums[i]*ans;
            if(nums[i]==0)cnt++;
            if(nums[i]!=0){
                k=k*nums[i];
            }
        }

        if(ans==0 && cnt>1){
            for(int i=0;i<n;i++){

                nums[i]=0;
            }
        }else if(cnt==1){
for(int i=0;i<n;i++){
    if(nums[i]==0)nums[i]=k;
    else nums[i]=0;
}
        }

        if(cnt==0){
            for(int i=0;i<n;i++){
                if(nums[i]!=0)nums[i]=ans/nums[i];
            }
        }
        return nums;
    }
};