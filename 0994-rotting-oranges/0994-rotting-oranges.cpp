class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int ans=0;
        int n=grid.size();
        int m=grid[0].size();
        int z=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if (grid[i][j]==1)z++;
            }
        }
        if(z==0)return 0;
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
if(grid[i][j]==2){
    q.push({i,j});
}
            }
        }
            int dr[]={-1,1,0,0};
            int dc[]={0,0,-1,1};
            while(!q.empty()){
                int sz=q.size();

    while(sz--){
auto a=q.front();
q.pop();
int x=a.first;
int y=a.second;
for(int i=0;i<4;i++){
   int  newr=x+dr[i];
    int newc=y+dc[i];
    if(newr>=0 && newr<n && newc>=0 && newc<m && grid[newr][newc]==1){
        grid[newr][newc]=2;
        q.push({newr,newc});
    }
            }
            
        }
        ans++;
    }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if (grid[i][j]==1)return -1;
            }
        }
        return ans-1;
    }
};