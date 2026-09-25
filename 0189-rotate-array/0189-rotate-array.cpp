class Solution {
public:
    void rotate(vector<int>& nums, int k) {

        vector<int> arr;
        int n = nums.size();

        k = k % n;

        for(int i = n-k; i < n-k+n; i++) {
            arr.push_back(nums[i % n]);
        }

        nums = arr;
    }
};