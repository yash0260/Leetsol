class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
         priority_queue<pair<double, pair<int, int>>> pq;
        for (const auto& cls : classes) {
            int pass = cls[0], total = cls[1];
            double gain = (double)(pass + 1) / (total + 1) - (double)pass / total;
            pq.push({gain, {pass, total}});
        }
          while (extraStudents-- > 0) {
            auto [gain, cls] = pq.top();
            pq.pop();
            int pass = cls.first, total = cls.second;
            pass++;
            total++;
            double newGain = (double)(pass + 1) / (total + 1) - (double)pass / total;
            pq.push({newGain, {pass, total}});
        }
double totalAverage = 0.0;
        while (!pq.empty()) {
            auto [gain, cls] = pq.top();
            pq.pop();
            int pass = cls.first, total = cls.second;
            totalAverage += (double)pass / total;
        }
        return totalAverage / classes.size();
    }
};