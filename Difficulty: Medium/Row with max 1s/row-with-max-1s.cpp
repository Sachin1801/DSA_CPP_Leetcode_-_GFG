// User function template for C++
class Solution {
  public:
    int rowWithMax1s(vector<vector<int>> &arr) {
        // code here
        int ans = -1;
        int rowSize = arr.size();
        int colSize = arr[0].size();
        int low = 0, high = colSize-1;
        int prevIdx = -1;
        for(int i=0;i<rowSize;i++){
            low = 0, high = colSize-1;
            while(low <= high){
                int mid = low + (high - low)/2;
                if(arr[i][mid]==1){
                    high = mid -1;
                }else{
                    low = mid +1;
                }
            }
            if(prevIdx == -1 && low < colSize){
                prevIdx = low;
                ans = i;
            }else if(prevIdx!=-1 && low < colSize){
                if(low < prevIdx){
                    prevIdx = low;
                    ans = i;
                }
            }else{
                continue;
            }
        }
        return ans;
    }
};