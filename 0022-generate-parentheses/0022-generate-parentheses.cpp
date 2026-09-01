class Solution {
public:

    void solve(int n, int open, int close,
               string curr, vector<string>& ans) {

        // If we have used n pairs
        if (curr.size() == 2 * n) {
            ans.push_back(curr);
            return;
        }

        // Choice 1: Add '('
        if (open < n) {
            solve(n, open + 1, close,
                  curr + '(', ans);
        }

        // Choice 2: Add ')'
        if (close < open) {
            solve(n, open, close + 1,
                  curr + ')', ans);
        }
    }

    vector<string> generateParenthesis(int n) {

        vector<string> ans;

        solve(n, 0, 0, "", ans);

        return ans;
    }
};