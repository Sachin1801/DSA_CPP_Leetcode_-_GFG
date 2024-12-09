class Solution {
private:
    int maxelement(vector<vector<int>>& mat, int rowsize, int colsize, int col){
        pair<int,int> maxele = {-1,-1};
        for(int i=0;i<rowsize;i++){
            if(mat[i][col]> maxele.first){
                maxele.first = mat[i][col];
                maxele.second = i;
            }
        }
        return maxele.second;
    }

public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int rowsize = mat.size();
        int colsize= mat[0].size();
        int low = 0, high = colsize-1;
        while(low<=high){
            int mid =(low+high)/2;
            int row = maxelement(mat,rowsize,colsize,mid);
            int left = mid - 1 >=0 ? mat[row][mid-1] : -1;
            int right = mid + 1 < colsize ? mat[row][mid+1] : -1;
            if(mat[row][mid]> left and mat[row][mid] > right){
                return {row,mid};
            }else if(mat[row][mid] < left){
                high = mid -1;
            }else{
                low = mid + 1;
            }
        }
        return {-1,-1};
    }
};