class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
      
queue<pair<pair<int,int>, int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                }
            }
        }
        
while(!q.empty()){
     int step=q.front().second;
    int row=q.front().first.first;
    int col=q.front().first.second;
   q.pop();
  int dx[4]={-1,0,1,0};
    int dy[4]={0,1,0,-1};
                for(int i=0;i<4;i++){
                    int nrow=row+dx[i];
                    int ncol=col+dy[i];
                     if(nrow>=0 && nrow<n && ncol>=0 && ncol<m &&
                    grid[nrow][ncol]==1 ){
                        q.push({{nrow,ncol},step+1});
                        grid[nrow][ncol]=2;
                    }
                }
                ans = max(ans, step);
            } 
            for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1) return -1;
            }
        }
            return ans;  
            
    }
};
