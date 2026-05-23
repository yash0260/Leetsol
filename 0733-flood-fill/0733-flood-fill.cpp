class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        int n = image.size();
        int m = image[0].size();
        int k = image[sr][sc];
        if(k == color) return image;
        queue<pair<int, int>> q;
        q.push({sr, sc});
        image[sr][sc]=color;
        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            int dx[4] = {-1, 0, 1, 0};
            int dy[4] = {0, 1, 0, -1};
            for (int i = 0; i < 4; i++) {
                int nrow = r + dx[i];
                int ncol = c + dy[i];
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                    image[nrow][ncol] == k) {
                    q.push({nrow, ncol});
                    image[nrow][ncol] = color;
                }
            }
        }
        return image;
    }
};