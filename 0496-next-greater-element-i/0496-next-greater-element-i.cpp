class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        int n = nums2.size();
        int m = nums1.size();

        stack<int> st;

        // next[i] = next greater element of nums2[i]
        vector<int> next(n);

        // Traverse from right to left
        for(int i = n - 1; i >= 0; i--) {

            // Remove elements which cannot be
            // the next greater element
            while(!st.empty() && st.top() <= nums2[i]) {
                st.pop();
            }

            // Find answer
            if(st.empty()) {
                next[i] = -1;
            }
            else {
                next[i] = st.top();
            }

            // Push current element
            st.push(nums2[i]);
        }

        // Find nums1 elements inside nums2
        for(int i = 0; i < m; i++) {

            int k = nums1[i];

            for(int j = 0; j < n; j++) {

                if(nums2[j] == k) {
                    nums1[i] = next[j];
                    break;
                }
            }
        }

        return nums1;
    }
};