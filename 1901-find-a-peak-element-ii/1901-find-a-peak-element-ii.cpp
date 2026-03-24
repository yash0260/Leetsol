class Solution {
public:
    int findmaxindex(vector<vector<int>>& mat, int n, int m, int col) {
        int maxvalue = -1;
        int index = -1;
        for (int i = 0; i < n; i++) {
            if (mat[i][col] > maxvalue) {
                maxvalue = mat[i][col];
                index = i;
            }
        }
        return index;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int low = 0, high = m - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            int maxrowindex = findmaxindex(mat, n, m, mid);
            int left;
            if (mid - 1 >= 0) {
                left = mat[maxrowindex][mid - 1];
            } else {
                left = -1;
            }

            int right;
            if (mid + 1 < m) {
                right = mat[maxrowindex][mid + 1];
            } else {
                right = -1;
            }
            if (mat[maxrowindex][mid] > left && mat[maxrowindex][mid] > right) {
                return {maxrowindex, mid};
            } else if (mat[maxrowindex][mid] < left) {
                high = mid - 1;

            } else {
                low = mid + 1;
            }
        }
        return {-1, -1};
    }
};