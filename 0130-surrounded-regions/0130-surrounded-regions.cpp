class Solution {
public:
void dfs(int i,int j,vector<vector<int>>&vis,vector<vector<char>>& board,int n,int m){
    vis[i][j]=1;
    int dr[]={-1,1,0,0};
    int dc[]={0,0,1,-1};
    for(int k=0;k<4;k++){
        int newr=i+dr[k];
        int newc=j+dc[k];
        if(newr>=0 && newc>=0 && newr<n && newc<m && board[newr][newc]=='O'&& vis[newr][newc]!=1){
            dfs(newr,newc,vis,board,n,m);
        }
    }
}
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>>vis(n,vector<int>(m,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 && board[i][j]=='O')dfs(i,j,vis,board,n,m); 
                if(j==0 && board[i][j]=='O')dfs(i,j,vis,board,n,m); 
                if(i==n-1 && board[i][j]=='O')dfs(i,j,vis,board,n,m); 
                if(j==m-1 && board[i][j]=='O')dfs(i,j,vis,board,n,m); 
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]!=1 && board[i][j]=='O'){
                board[i][j]='X';
                }
            }
        }
        return ;
    }
};