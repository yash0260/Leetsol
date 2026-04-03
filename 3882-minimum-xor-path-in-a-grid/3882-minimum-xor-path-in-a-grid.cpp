class Solution {
public:
    int m, n;
    vector<vector<int>> grid;
    vector<vector<vector<int>>> dp;

    vector<int> solve(int i, int j) {
        if (i == m - 1 && j == n - 1) {
            vector<int> base(1024, 0);
            base[grid[i][j]] = 1;
            return base;
        }

        if (!dp[i][j].empty()) return dp[i][j];

        vector<int> res(1024, 0);

        if (i + 1 < m) {
            vector<int> down = solve(i + 1, j);
            for (int x = 0; x < 1024; x++) {
                if (down[x]) {
                    res[x ^ grid[i][j]] = 1;
                }
            }
        }

        if (j + 1 < n) {
            vector<int> right = solve(i, j + 1);
            for (int x = 0; x < 1024; x++) {
                if (right[x]) {
                    res[x ^ grid[i][j]] = 1;
                }
            }
        }

        return dp[i][j] = res;
    }

    int minCost(vector<vector<int>>& g) {
        grid = g;
        m = grid.size();
        n = grid[0].size();

        dp.resize(m, vector<vector<int>>(n));

        vector<int> ans = solve(0, 0);

        for (int x = 0; x < 1024; x++) {
            if (ans[x]) return x;
        }

        return 0;
    }
};