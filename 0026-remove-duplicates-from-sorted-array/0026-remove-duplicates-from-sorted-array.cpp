class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
  

        vector<int> arr;
        arr.push_back(nums[0]); // Always keep first element

        for (int i = 1; i < n; ++i) {
            if (nums[i] != nums[i - 1]) {
                arr.push_back(nums[i]);
            }
        }

        // Copy arr back to nums
        for (int i = 0; i < arr.size(); ++i) {
            nums[i] = arr[i];
        }

       return arr.size();
      
    }
    
};
