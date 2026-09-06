
class Solution {
int helper(int i,int j,string &s,string &t,vector<vector<int>>&dp){
        if (j == t.size()) return 1;
        if (i == s.size()) return 0;
        if (dp[i][j] != -1) return dp[i][j];
         if (s[i] == t[j]) {
            // Option 1: take this character and move both indices
            int take = helper(i + 1, j + 1, s, t, dp);

            // Option 2: skip this character of s and move only in s
            int notTake = helper(i + 1, j, s, t, dp);

            // Store result in dp table
            return dp[i][j] = take + notTake;
        }else {
            // If characters do not match, we can only skip s[i]
            return dp[i][j] = helper(i + 1, j, s, t, dp);
        }
}
public:
    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return helper(0,0,s,t,dp);
    }
};