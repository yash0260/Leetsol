class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {

        int m = grid.size();
        int n = grid[0].size();

        if (m == 1 && n == 1)
            return 0;

        vector<vector<vector<bool>>> visited(
            m, vector<vector<bool>>(n, vector<bool>(k + 1, false)));

        queue<vector<int>> q;

        q.push({0, 0, k, 0});
        visited[0][0][k] = true;

        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};

        while (!q.empty()) {

            auto curr = q.front();
            q.pop();

            int x = curr[0];
            int y = curr[1];
            int rem = curr[2];
            int dist = curr[3];

            for (int i = 0; i < 4; i++) {

                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx < 0 || ny < 0 || nx >= m || ny >= n)
                    continue;

                if (nx == m - 1 && ny == n - 1)
                    return dist + 1;

                if (grid[nx][ny] == 0) {

                    if (!visited[nx][ny][rem]) {
                        visited[nx][ny][rem] = true;
                        q.push({nx, ny, rem, dist + 1});
                    }

                } else {

                    if (rem > 0 && !visited[nx][ny][rem - 1]) {
                        visited[nx][ny][rem - 1] = true;
                        q.push({nx, ny, rem - 1, dist + 1});
                    }
                }
            }
        }

        return -1;
    }
};