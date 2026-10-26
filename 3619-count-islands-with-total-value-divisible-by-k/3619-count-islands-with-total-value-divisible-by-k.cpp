class Solution {
public:
void dfs(int i,int j,vector<vector<int>>&grid,long long& sum,int k){
    sum+=grid[i][j];
grid[i][j]=0;
 int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        for(int k=0;k<4;k++){
        int newr=dr[k]+i;
        int newc=dc[k]+j;
       if (newr >= 0 && newr < grid.size() &&
        newc >= 0 && newc < grid[0].size() &&
        grid[newr][newc] != 0) {
        dfs(newr, newc, grid,sum,k);
    }
        }

}
    int countIslands(vector<vector<int>>& grid, int k) {
       int n=grid.size();
       int m=grid[0].size();
       int cnt=0;
       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]!=0){
                long long sum=0;
            dfs(i,j,grid,sum,k);
            if(sum%k==0)cnt++;
            }
        }
       }
       return cnt; 
    }
};