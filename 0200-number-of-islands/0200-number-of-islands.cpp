class Solution {
public:

    void bfs(int row, int col, vector<vector<char>>& grid, int n, int m) {

        queue<pair<int, int>> q;

        q.push({row, col});
        grid[row][col] = '2';

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while(!q.empty()) {

            auto [r, c] = q.front();
            q.pop();

            for(int i = 0; i < 4; i++) {

                int newr = r + dr[i];
                int newc = c + dc[i];

                if(newr >= 0 && newr < n &&
                   newc >= 0 && newc < m &&
                   grid[newr][newc] == '1') {

                    grid[newr][newc] = '2';

                    q.push({newr, newc});
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        int islands = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                if(grid[i][j] == '1') {

                    islands++;

                    bfs(i, j, grid, n, m);
                }
            }
        }

        return islands;
    }
};