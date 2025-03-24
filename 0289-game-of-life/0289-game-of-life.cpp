class Solution {

private:
    void check_zero(vector<vector<int>>&board,int i, int j){
        int one_cnt=0;
        if(i-1>=0){
            //top-left
            if(j-1>=0 && board[i-1][j-1]>0) one_cnt++;
            //top-right
            if(j+1<board[0].size() && board[i-1][j+1]>0) one_cnt++;
            //top
            if(board[i-1][j]>0) one_cnt++;
        }
        //left
        if(j-1>=0 && board[i][j-1]>0)one_cnt++;
        //right
        if(j+1 < board[0].size() && board[i][j+1]>0) one_cnt++;

        if(i+1 < board.size()){
            //bottom left
            if(j-1>=0 && board[i+1][j-1]>0) one_cnt++;
            //bottom
            if(j+1<board[0].size() && board[i+1][j+1]>0) one_cnt++;
            //bottom right
            if(board[i+1][j]>0) one_cnt++;
        }
        if(board[i][j]==0 && one_cnt==3) board[i][j]=-1;
        if(board[i][j]==1){
            if(one_cnt<2 || one_cnt > 3) board[i][j]=2;
        }
    }
public:
    void gameOfLife(vector<vector<int>>& board) {
        int rowsize= board.size();
        int colsize = board[0].size();
        for(int i=0;i<rowsize;i++){
            for(int j=0;j<colsize;j++){
                check_zero(board,i,j);
            }
        }
        for(int i=0;i<rowsize;i++){
            for(int j=0;j<colsize;j++){
                if(board[i][j]==2) board[i][j]=0;
                if(board[i][j]==-1) board[i][j]=1;
            }
        }
        return;
        
    }
};