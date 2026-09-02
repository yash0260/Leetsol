class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        vector<int> pre(n, 0), post(n, 0); // prefix max , postfix max
        pre[0] = height[0];
        post[n - 1] = height[n - 1];
        for (int i = 1; i < n; ++i) {
            pre[i] = max(pre[i - 1], height[i]);
        }
        for (int i = n - 2; i >= 0; --i) {
            post[i] = max(post[i + 1], height[i]);
        }
        int i = 0, j = n - 1, mx = INT_MIN;
        while (i < j) // two pointers concept
        {
            int area = min(pre[i], post[j]) * (j - i);
            mx = max(mx, area);
            if (pre[i] > post[j])
                j--;
            else
                i++;
        }
        return mx;
    }
};