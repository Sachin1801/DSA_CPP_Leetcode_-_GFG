// Last updated: 12/14/2025, 4:15:43 PM
class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int diag= 0;
        int ans = 0;
        int rowSize= dimensions.size();
        for(int i = 0;i < rowSize;i++ ){
            int len = dimensions[i][0];
            int width = dimensions[i][1];
            int curr_diag= (len*len) + (width*width);
            if(curr_diag >=diag){
                if(curr_diag == diag){
                    ans = max(ans,len*width);
                }else{
                    diag = max(diag,curr_diag);
                    ans = len * width;
                }
            }
        }
        return ans;
    }
};