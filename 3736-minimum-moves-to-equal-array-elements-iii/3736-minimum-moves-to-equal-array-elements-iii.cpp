class Solution {
public:
    int minMoves(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int median=nums[n-1];
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=abs(nums[i]-median);
        }
        return sum;
    }
};