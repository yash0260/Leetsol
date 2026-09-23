class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
  int n=nums.size();
  vector<int>arr;
  for(int i=0;i<n;i++){
    int k=target-nums[i];
    for(int j=i+1;j<n;j++){
        if(nums[j]==k){
arr.push_back(i);
arr.push_back(j);
break;
        }
    }
  }
  return arr;      
    }
};