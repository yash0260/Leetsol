
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if (obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1)
            return 0;
        vector<vector<long long>> dp(m, vector<long long>(n, 0));
        for (int j = n-1; j >=0; j--) {
            if(obstacleGrid[m-1][j]!=1)
            dp[m-1][j]=1;
            else break;
        }
        for (int j = m-1; j >=0; j--) {
            if(obstacleGrid[j][n-1]!=1)
            dp[j][n-1]=1;
            else break;
        }
        for (int i = m - 2; i >= 0; i--) {
            for (int j = n - 2; j >= 0; j--) {
                if (obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                } else {
                    dp[i][j] = 1LL*(dp[i + 1][j] + dp[i][j + 1]);
                }
            }
        }
        return dp[0][0];
    }
};