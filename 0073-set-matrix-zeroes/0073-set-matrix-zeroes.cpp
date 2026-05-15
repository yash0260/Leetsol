class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int>r(m,0);
        vector<int>c(n,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
if(matrix[i][j]==0){
r[j]=1;
c[i]=1;
}
            }
        }
    for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
if(
r[j]==1||
c[i]==1){
matrix[i][j]=0;
}
            }
        }
        return ;
    }
};