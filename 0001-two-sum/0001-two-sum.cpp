class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mpp;
        
        for(int i=0;i<nums.size();i++){
            int a=nums[i];
            int moreneeded=target-a;
            if(mpp.find(moreneeded)!=mpp.end()){
                return {mpp[moreneeded],i};
            }
            mpp[a]=i;
        }
        return {-1,-1};
    }
};