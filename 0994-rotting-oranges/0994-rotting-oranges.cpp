class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
       int n=grid.size();
       int m=grid[0].size();
       queue<pair<pair<int,int>,int>> q;

       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==2){
            q.push({{i,j},0});
            }
        }
       }
        int count = 0;

        int dc[] = {-1,1,0,0};
        int dr[] = {0,0,1,-1};

        while(!q.empty()){

            int r = q.front().first.first;
            int c = q.front().first.second;
            count = q.front().second;

            q.pop();
            for(int i=0;i<4;i++){

                int newr = dr[i] + r;
                int newc = dc[i] + c;

                if(newr >= 0 && newr < n &&
                   newc >= 0 && newc < m &&
                   grid[newr][newc] == 1){

                    grid[newr][newc] = 2;

                    q.push({{newr,newc},count+1});
                }
            }
        }

        // Check if fresh oranges remain
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }

        return count;
    }
};