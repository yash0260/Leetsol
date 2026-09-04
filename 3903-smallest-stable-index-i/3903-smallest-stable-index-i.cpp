class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>maxi(n,-1);
        vector<int>mini(n,-1);
        int ans=INT_MAX;
        int res=INT_MIN;
        for(int i=0;i<n;i++){
            maxi[i]=max(nums[i],res);
            res=max(nums[i],maxi[i]);
        }
        for(int j=n-1;j>=0;j--){
            mini[j]=min(nums[j],ans);
            ans=min(ans,nums[j]);
        }
        for(int i=0;i<n;i++){
            nums[i]=maxi[i]-mini[i];
        }
        int result=-1;
        for(int i=0;i<n;i++){
            if(nums[i]<=k){result=i;
            break;
            }
        }
return result;
    }
};