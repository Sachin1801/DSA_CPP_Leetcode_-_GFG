class Solution {
    
    private:
        int computeLis(int idx, int prevIdx, vector<int> &arr, vector<vector<int>> &dp){
            //base case
            if(idx >= arr.size()) return 0;
            
            if(dp[idx][prevIdx+1] != -1 ) return dp[idx][prevIdx+1 ];
            
            //two cases 
            //case 1: Not take 
            int len = 0;
            len = 0 + computeLis(idx+1,prevIdx, arr, dp);
            
            //case 2: Take the element
            if(prevIdx == -1 || arr[idx] > arr[prevIdx]){
                len = max(len, 1 + computeLis(idx + 1, idx, arr, dp));
            }
            
            return dp[idx][prevIdx+1]  = len;
        }
    
  public:
    int lis(vector<int>& arr) {
        // code here
        
        int n = arr.size();
        
        //edge case
        if(arr.size()==1) return 1;
        
        vector<vector<int>> dp(n,vector<int>(n+1,-1));  
        
        //compute the lis
        return computeLis(0,-1,arr,dp);
    }
};