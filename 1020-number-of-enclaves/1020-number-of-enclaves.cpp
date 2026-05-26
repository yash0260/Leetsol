class Solution {
    void dfs(int x,int y,vector<vector<int>>&board,vector<vector<int>>&vis){
        int n=board.size();
        int m=board[0].size();
        vis[x][y]=1;
        int delx[]={-1,0,1,0};
        int dely[]={0,1,0,-1};
 for(int i=0;i<4;i++){
            int newx=x+delx[i];
            int newy=y+dely[i];
             if(newx>=0 && newx<n && newy>=0 &&newy<m && !vis[newx][newy] && board[newx][newy]==1 ){
                dfs(newx,newy, board,vis);
            }

            }
}
public:
    int numEnclaves(vector<vector<int>>& board) {
     int n=board.size();
     int m=board[0].size();
         vector<vector<int>>vis(n,vector<int>(m,0));
for(int i = 0; i < n; i++) {
            if(board[i][0] == 1) dfs(i, 0, board, vis);
            if(board[i][m-1] == 1) dfs(i, m-1, board, vis);
        }

for(int j = 0; j < m; j++) {
            if(board[0][j] == 1) dfs(0, j, board, vis);
            if(board[n-1][j] == 1) dfs(n-1, j, board, vis);
        }
int cnt=0;
for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(board[i][j]==1 && vis[i][j]==0){
                cnt++;
            }
        }
    }
    return cnt;

    }
};