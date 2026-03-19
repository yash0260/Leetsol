class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        vector<int>sumx(col,0);
        vector<int>sumy(col,0);
        int res=0;
        for(int i=0;i<row;i++){
            int rx=0,ry=0;
            for(int j=0;j<col;j++){
                if(grid[i][j]=='X')rx++;
                else if(grid[i][j]=='Y')ry++;
                sumx[j]+=rx;
                sumy[j]+=ry;
                if(sumx[j]>0 && sumx[j]==sumy[j])res++;
            }
        }
        return res;
    }
};