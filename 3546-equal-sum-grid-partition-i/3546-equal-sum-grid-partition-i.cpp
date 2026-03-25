class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<long long> row(n, 0);
        vector<long long> col(m, 0);

        // Row sums
        for(int i = 0; i < n; i++){
            row[i] = accumulate(grid[i].begin(), grid[i].end(), 0LL);
        }

        // Column sums
        for(int j = 0; j < m; j++){
            for(int i = 0; i < n; i++){
                col[j] += grid[i][j];
            }
        }

        long long total = accumulate(row.begin(), row.end(), 0LL);

        // Horizontal cut
        long long curr = 0;
        for(int i = 0; i < n - 1; i++){
            curr += row[i];
            if(curr == total - curr) return true;
        }

        // Vertical cut
        curr = 0;
        for(int j = 0; j < m - 1; j++){
            curr += col[j];
            if(curr == total - curr) return true;
        }

        return false;
    }
};