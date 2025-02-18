class Solution {
private:
    bool canPlace(int row,int col, vector<string> &board, int n) {
        //check upper left diagonal
        int duprow = row, dupcol = col;
        while(row >=0 && col >=0){
            if(board[row][col] == 'Q')
                return false;
            row--;
            col--;
        }
        //bottom left diagoanal
        col = dupcol;
        row = duprow;
        while(col >=0){
            if(board[row][col]=='Q') return false;
            col--;
        }

        col = dupcol, row = duprow;
        while(row < n && col >=0){
            if(board[row][col]=='Q') return false;
            row++;
            col--;
        }
        return true;
        
    }

    void solve(int col, vector<vector<string>>& ans, vector<string>& board,
               int n) {
                if(col==n){
                    ans.push_back(board);
                    return;
                }
                    for(int row=0;row<n;row++){
                    if(canPlace(row,col,board,n)){
                        board[row][col]='Q';
                        solve(col+1, ans,board,n);
                        board[row][col]='.';
                    }
                }
               }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n, '.');
        for (int i = 0; i < n; i++) {
            board[i] = s;
        }
        solve(0, ans, board, n);
        return ans;
    }
};