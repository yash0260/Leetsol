class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;

        vector<int> leftsmall(n), rightsmall(n);

        // Find Nearest Smaller to Left (NSL)
        for (int i = 0; i < n; i++) {

            // Remove all elements greater than or equal to current
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }

            // If no smaller element exists on the left
            if (st.empty()) {
                leftsmall[i] = 0;
            }
            // Otherwise, rectangle starts after the smaller element
            else {
                leftsmall[i] = st.top() + 1;
            }

            st.push(i);
        }

        // Clear the stack
        while (!st.empty()) {
            st.pop();
        }

        // Find Nearest Smaller to Right (NSR)
        for (int i = n - 1; i >= 0; i--) {

            // Remove all elements greater than or equal to current
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }

            // If no smaller element exists on the right
            if (st.empty()) {
                rightsmall[i] = n - 1;
            }
            // Otherwise, rectangle ends before the smaller element
            else {
                rightsmall[i] = st.top() - 1;
            }

            st.push(i);
        }

        // Calculate maximum rectangle area
        int maxArea = 0;

        for (int i = 0; i < n; i++) {
            int width = rightsmall[i] - leftsmall[i] + 1;
            int area = heights[i] * width;
            maxArea = max(maxArea, area);
        }

        return maxArea;
    }
};