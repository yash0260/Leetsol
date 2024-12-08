class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        int n = events.size();
        vector<int> maxValues(n, 0); 
        maxValues[0] = events[0][2];
        for (int i = 1; i < n; ++i) {
            maxValues[i] = max(maxValues[i - 1], events[i][2]);
        }

        int result = 0;
        auto binarySearch = [&](int index) {
            int left = 0, right = index - 1, res = -1;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (events[mid][1] < events[index][0]) {
                    res = mid;
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
            return res;
        };
       for (int i = 0; i < n; ++i) {
            result = max(result, events[i][2]);
            int prevIndex = binarySearch(i);
            if (prevIndex != -1) {
                result = max(result, events[i][2] + maxValues[prevIndex]);
            }
        }

        return result;
    }
};