class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>vis(n,vector<int> (m,0));
        queue<pair<pair<int,int>,int>>q;
        vector<vector<int>>ans(n,vector<int> (m,0));

        int step=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0 && vis[i][j]==0){
                    vis[i][j]=1;
q.push({{i,j},step});
ans[i][j]=step;
                }
            }
        }
        int a[4]={+1,0,-1,0};
        int b[4]={0,-1,0,+1};
        while(!q.empty()){
            int row=q.front().first.first;
            int col=q.front().first.second;
            int step =q.front().second;
            q.pop();
for(int i=0;i<4;i++){
    int nrow=row+a[i];
    int ncol=col+b[i];
    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol]){
        int newStep = step + 1;
        vis[nrow][ncol]=1;
        ans[nrow][ncol]=newStep ;
q.push({{nrow,ncol},newStep });
    }
}
        }
        return ans;
    }
};