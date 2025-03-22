class Solution {
private:
    void mark_island(vector<vector<char>>& grid, int i, int j,int row, int col){
        if(i<0 || j < 0) return;
        if(i>=row || j >=col) return;

        //we mark the current index[i][j]
        if(grid[i][j]=='0' || grid[i][j]=='2') return;
        grid[i][j]='2';

        //4 places to check
        //up -> [i-1][j]
        mark_island(grid,i-1,j,row,col);
        //down -> [i+1][j]
        mark_island(grid,i+1,j,row,col);
        //right -> [i][j+1]
        mark_island(grid,i,j+1,row,col);
        //left -> [i][j-1]
        mark_island(grid,i,j-1,row,col);
        return;
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        int row_size = grid.size();
        int col_size = grid[0].size();
        for(int i=0;i<row_size;i++){
            for(int j=0;j<col_size;j++){
                if(grid[i][j]=='1'){
                    mark_island(grid,i,j,row_size,col_size);
                    ans++;
                }
            }
        }
        return ans;
    }
};