class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rowsize= matrix.size();
        int colsize = matrix[0].size();
        if(target < matrix[0][0] or target > matrix[rowsize-1][colsize-1])
            return false;
        int row =0;
        int col = colsize -1;
        while(row < rowsize and col >= 0){
            if(matrix[row][col]==target){
                return true;
            }else if(matrix[row][col] > target){
                col--;
            }else{
                row++;
            }
        }
        return false;
    }
};