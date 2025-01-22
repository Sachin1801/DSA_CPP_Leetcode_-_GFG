class Solution {

private:
    void dfs(vector<vector<int>>& board, int i, int j){
        board[i][j]=-1;
        if(i-1>=0 && board[i-1][j]==1) dfs(board,i-1,j);
        if(i+1< board.size() && board[i+1][j]==1) dfs(board,i+1,j);
        if(j-1>=0 && board[i][j-1]==1) dfs(board,i,j-1);
        if(j+1< board[0].size() && board[i][j+1]==1) dfs(board,i,j+1);
    }

public:
    int numEnclaves(vector<vector<int>>& board) {
        int row = board.size();
        int col = board[0].size();
        //first row ( upper n=boundry)
        for(int j=0; j< col;j++){
            if(board[0][j]==1){
                dfs(board, 0,j);
            }
        }

        //first column
        for(int i=0;i<row;i++){
            if(board[i][0]==1)
                dfs(board,i,0);
        }

        //last row
        
        for(int j=0; j<col;j++){
            if(board[row-1][j]==1)
                dfs(board,row-1,j);
        }

        //last col
        for(int i=0;i<row;i++){
            if(board[i][col-1]==1)
                dfs(board,i,col-1);
        }
        int cnt = 0;

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(board[i][j]==1)
                    cnt++;
                else if(board[i][j]==-1)
                    board[i][j]=1;
            }
        }
        return cnt;
    }
};