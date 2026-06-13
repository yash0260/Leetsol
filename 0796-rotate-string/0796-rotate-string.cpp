class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size()) return false;

        string q = goal + goal;
        int n = s.size();
        int m = q.size();

        for (int j = 0; j <= m - n; ++j) {
            int i = 0;
            while (i < n && s[i] == q[j + i]) {
                i++;
            }
            if (i == n) {
                return true; // found a match
            }
        }
        return false; // no match found
    }
};