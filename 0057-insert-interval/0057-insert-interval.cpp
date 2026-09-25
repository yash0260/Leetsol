class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());  // sort by start time

        vector<vector<int>> res;

        int currStart = intervals[0][0];
        int currEnd   = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++) {
            if (currEnd >= intervals[i][0]) {
                // Overlapping → extend the interval
                currEnd = max(currEnd, intervals[i][1]);
            } else {
                // No overlap → push current interval and start new one
                res.push_back({currStart, currEnd});
                currStart = intervals[i][0];
                currEnd   = intervals[i][1];
            }
        }

        // Push the last interval
        res.push_back({currStart, currEnd});

        return res;
    }
};
