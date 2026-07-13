class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int sum=INT_MIN;
        int a=0;
        for(int i=0;i<n;i++){
            if(a<0)a=0;
    a+=nums[i];
    sum=max(sum,a);
        }
        return sum;
    }
};