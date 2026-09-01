class Solution {
public:
bool solve(vector<vector<char>> & board,string &word,int row,int col,int index){
    if(index==word.size()){
        return true;
    }
    int m=board.size();
    int n=board[0].size();
    if(row<0 || row>=m || col<0 || col>=n){
        return false;
    }
    if(board[row][col]!=word[index]){
        return false;
    }
    char temp=board[row][col];
    board[row][col]='#';
    bool found =
            solve(board, word, row - 1, col, index + 1) ||   // up
            solve(board, word, row + 1, col, index + 1) ||   // down
            solve(board, word, row, col - 1, index + 1) ||   // left
            solve(board, word, row, col + 1, index + 1); 
    board[row][col] = temp;

    return found;


}
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();
        for(int row=0;row<m;row++){
            for(int col=0;col<n;col++){
                if(solve(board,word,row,col,0)){
                    return true;
                }
            }
        }
        return false;
    }
};