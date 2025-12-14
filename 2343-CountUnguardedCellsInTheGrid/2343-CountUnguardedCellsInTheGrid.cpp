// Last updated: 12/14/2025, 4:16:48 PM
class Solution {
public:
    void mark_safe(vector<vector<int>> &grid, int i, int j,int rowSize, int colSize){

        // left direction
        int r =i,c=j-1;
        while(c>=0){
            //wall -> break or guard -> break
            if(grid[r][c] == -2 || grid[r][c] == -1){
                break;
            }
            else{
                grid[r][c]=1;
                c--;
            }
        }
        
        //right direction
        r = i, c = j+1;
        while(c < colSize){
            if(grid[r][c] == -2 || grid[r][c] == -1){
                break;
            }
            else{
                grid[r][c]=1;
                c++;
            }
        }

        //up direction
        r = i -1, c = j;
        while(r >= 0){
            if(grid[r][c] == -2 || grid[r][c] == -1){
                break;
            }
            else{
                grid[r][c]=1;
                r--;
            }
        }

        //bottom direction
        r= i+1, c = j;
        while(r < rowSize){
            if(grid[r][c] == -2 || grid[r][c] == -1){
                break;
            }
            else{
                grid[r][c]=1;
                r++;
            }
        }

        return;
    }

    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m,vector<int>(n,0));

        //mark the guards : -1
        for(auto vec: guards){
            int r = vec[0];
            int c = vec[1];

            grid[r][c] = -1;
        }

        // mark the walls = -2
        for(auto vec: walls ){
            int r = vec[0];
            int c = vec[1];

            grid[r][c] = -2;
        }

        // now for each guard mark the safe boxes / indexes
        for(auto vec: guards){
            int r = vec[0];
            int c = vec[1];

            mark_safe(grid,r,c,m,n);
        }

        //count the non safe boxes
        int ans = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    ans++;
                }
            }
        }
        return ans;
    }
};