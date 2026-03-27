class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> f(n, vector<int>(m));

        for(int i = 0; i < n; i++){
            int shift = k % m;

            for(int j = 0; j < m; j++){
                if(i % 2 == 0){
                    f[i][j] = mat[i][(j + shift) % m];
                } else {
                    f[i][j] = mat[i][(j - shift + m) % m];
                }
            }
        }

        return mat == f;
    }
};