class Solution {
private: 
    bool check(vector<vector<int>>& matrix, int target, int RowNo){
        int low = 0;
        int high = matrix[0].size();
        while(low<=high){
            int mid = (low+high)/2;
            if(matrix[RowNo][mid]==target){
                return true;
            }else if(matrix[RowNo][mid]> target){
                high = mid -1 ;
            }else{ 
                low = mid + 1;
            }
        }
        return false;
    }

public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rowsize= matrix.size();
        int colsize= matrix[0].size();
        if(target < matrix[0][0] or target > matrix[rowsize-1][colsize-1])
            return false;
        for(int i=0;i<rowsize;i++){
            if(target >=matrix[i][0] and target <=matrix[i][colsize-1]){
                return check(matrix,target, i);
            }
        }
        return false;
    }
};