class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int left = 0;
        int right = m - 1;
        int top = 0;
        int bottom = n - 1;
        vector<int> arr;
        while (top <= bottom && left <= right) {

            for (int j = left; j <= right; j++) {
                arr.push_back(matrix[top][j]);
            }
            top++;
           for(int i=top;i<=bottom;i++){
            arr.push_back(matrix[i][right]);
           }
            right--;
            if (top <= bottom) {
                for (int j = right; j >= left; j--) {
                    arr.push_back(matrix[bottom][j]);
                }
                bottom--;
            }
            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    arr.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        return arr;
    }
};