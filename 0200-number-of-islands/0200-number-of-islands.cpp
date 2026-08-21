class Solution {
public:
 void dfs(int row, int col, vector<vector<char>>& grid,int n,int m) {
grid[row][col]='2';
    int dr[]={-1,1,0,0};
    int dc[]={0,0,-1,1};
    for(int i=0;i<4;i++){
int newr=row+dr[i];
int newc=col+dc[i];
 if (newr >= 0 && newr < n && newc >= 0 && newc < m &&
            grid[newr][newc] == '1')
dfs(newr,newc,grid,n,m);
    }
    }

    int numIslands(vector<vector<char>>& grid) {
         int n = grid.size();
        int m = grid[0].size();

        int islands = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (grid[i][j] == '1') {
                    islands++;
                    dfs(i, j, grid,n,m);
                }

            }
        }

        return islands;
    }
};