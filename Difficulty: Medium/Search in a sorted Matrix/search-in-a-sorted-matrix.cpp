class Solution {
  public:
    bool searchMatrix(vector<vector<int>> &mat, int x) {
        // code here
        int rowSize = mat.size();
        int colSize = mat[0].size();
        
        for(int i=0;i<rowSize;i++){
            int low = mat[i][0], high = mat[i][colSize-1];
            if( x < low ) return false;
            else if(x > high){
                continue;
            }
            else if(x == low || x == high){
                return true;
            }else{
                //binary search on col
                int lowIdx = 0;
                int highIdx =  colSize -1;
                while(lowIdx <= highIdx ){
                    int mid = lowIdx + (highIdx - lowIdx)/2;
                    if(mat[i][mid]==x) return true;
                    else if(mat[i][mid] > x) highIdx = mid - 1;
                    else lowIdx= mid + 1;
                }
                return false;
            }
        }
        return false;
    }
};