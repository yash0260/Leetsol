class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mpp;
        vector<int> arr;

        int n = nums.size();

        // Store each number and its index
        for (int i = 0; i < n; i++) {
            mpp[nums[i]] = i;
        }

        for (int i = 0; i < n; i++) {
            int k = target - nums[i];

            if (mpp.find(k) != mpp.end() && mpp[k] != i) {
                arr.push_back(i);
                arr.push_back(mpp[k]);
                break;
            }
        }

        return arr;
    }
};