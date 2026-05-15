class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] > nums[high]) {
                // min must be to the right of mid
                low = mid + 1;
            } else {
                // min is at mid or to the left
                high = mid;
            }
        }

        return nums[low];
    }
};