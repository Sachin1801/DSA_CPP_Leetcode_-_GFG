class Solution {
private:
    void dfs(vector<vector<char>>& board, int i, int j){
        board[i][j]='V';
        if(i-1>=0 && board[i-1][j]=='O') dfs(board,i-1,j);
        if(i+1< board.size() && board[i+1][j]=='O') dfs(board,i+1,j);
        if(j-1>=0 && board[i][j-1]=='O') dfs(board,i,j-1);
        if(j+1< board[0].size() && board[i][j+1]=='O') dfs(board,i,j+1);
    }

public:
    void solve(vector<vector<char>>& board) {
        // vector<vector<bool>> visited(board.size(),vector<int>(board[0].size(), false));
        int row = board.size();
        int col = board[0].size();
        //first row ( upper n=boundry)
        for(int j=0; j< col;j++){
            if(board[0][j]=='O'){
                dfs(board, 0,j);
            }
        }

        //first column
        for(int i=0;i<row;i++){
            if(board[i][0]=='O')
                dfs(board,i,0);
        }

        //last row
        
        for(int j=0; j<col;j++){
            if(board[row-1][j]=='O')
                dfs(board,row-1,j);
        }

        //last col
        for(int i=0;i<row;i++){
            if(board[i][col-1]=='O')
                dfs(board,i,col-1);
        }

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(board[i][j]=='O')
                    board[i][j]='X';
                else if(board[i][j]=='V')
                    board[i][j]='O';
            }
        }
        return ;
    }
};