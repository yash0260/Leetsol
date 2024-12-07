class Solution {
public:
   
    bool canDivide(vector<int>& nums, int maxPenalty, int maxOperations) {
        int operations = 0;
        for (int num : nums) {
            if (num > maxPenalty) {
                
                operations += (num - 1) / maxPenalty;
                if (operations > maxOperations) {
                    return false;
                }
            }
        }
        return true; 
    }

   
    int minimumSize(vector<int>& nums, int maxOperations) {
        int left = 1; 
        int right = *max_element(nums.begin(), nums.end());
        int result = right;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canDivide(nums, mid, maxOperations)) {
                result = mid;
                right = mid - 1;
            } else {
                left = mid + 1; 
            }
        }

        return result;
    }
};
