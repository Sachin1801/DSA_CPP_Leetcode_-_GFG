class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size(), col = matrix[0].size();

        int result = 0;

        vector<int> prevHgt(col,0);

        for(int i = 0; i< rows; i++){
            vector<int> currHgt = matrix[i];
            for(int j = 0; j<col; j++){
                // Step 1: compute the currHgt of the row
                if(currHgt[j] > 0){
                    currHgt[j] += prevHgt[j];
                }
            }
            // Sort the columns based on the currHgt
            prevHgt = currHgt;
            sort(currHgt.begin(), currHgt.end(), greater<int>());

            // Update the result for max area 
            int streak = 0;
            int minHgt = INT_MAX;
            for(int j = 0; j< col; j++){
                int currH = currHgt[j];
                if(currH > 0){
                    streak++;
                    minHgt = min(currH, minHgt);
                    result = max(result, streak*minHgt);
                }else{
                    streak = 0;
                }
            }
        }

        return result;  
    }
};