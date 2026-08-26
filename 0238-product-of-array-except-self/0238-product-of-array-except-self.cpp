class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int n = nums.size();

        vector<int> answer(n);

        // Store left products
        int left = 1;

        for(int i = 0; i < n; i++) {
            answer[i] = left;
            left = left * nums[i];
        }

        // Multiply by right products
        int right = 1;

        for(int i = n - 1; i >= 0; i--) {
            answer[i] = answer[i] * right;
            right = right * nums[i];
        }

        return answer;
    }
};