class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n=nums.size();
        vector<long long >prefixgcd(n);
        long long mx=0;
        for(int i=0;i<n;i++){
            mx=max(mx,(long long)nums[i]);
            prefixgcd[i]=gcd(nums[i],mx);
        }
        sort(prefixgcd.begin(),prefixgcd.end());
        int l=0,r=n-1;
        long long ans=0;
        while(l<r){
            ans+=gcd(prefixgcd[l],prefixgcd[r]);
            l++;
            r--;
        }
        return ans;
    }
};