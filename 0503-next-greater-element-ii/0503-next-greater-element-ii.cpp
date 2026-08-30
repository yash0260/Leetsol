class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
              int n = nums.size();

        // Initially, assume no greater element exists
        vector<int> result(n, -1);

        stack<int> st;

        // Traverse the array twice
        for(int i = 2 * n - 1; i >= 0; i--) {

            // Convert virtual index to actual index
            int index = i % n;

            // Remove elements smaller than or equal to current
            while(!st.empty() && st.top() <= nums[index]) {
                st.pop();
            }

            // We only need to fill answers during
            // the second/actual traversal
            if(i < n) {
                if(!st.empty()) {
                    result[index] = st.top();
                }
            }

            // Push current element
            st.push(nums[index]);
        }

        return result;
    }
};