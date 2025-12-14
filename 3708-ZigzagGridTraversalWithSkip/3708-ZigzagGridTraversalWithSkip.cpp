// Last updated: 12/14/2025, 4:15:20 PM
class Solution {
public:
    vector<int> zigzagTraversal(vector<vector<int>>& grid) {
        vector<int> ans;
        int colsize = grid[0].size();
        for(int i=0;i<grid.size();i++){
            int j;
            if(i%2==0){
                j=0;
                while(j<colsize){
                    ans.push_back(grid[i][j]);
                    j+=2;
                }
            }
            else{
                //odd row
                j = colsize%2==0 ? colsize-1 : colsize-2;
                while(j>=0){
                    ans.push_back(grid[i][j]);
                    j-=2;
                }
            }
        }
        return ans;
    }
};