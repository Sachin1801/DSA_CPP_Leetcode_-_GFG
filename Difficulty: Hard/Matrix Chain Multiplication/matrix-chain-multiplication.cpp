class Solution {
  public:
  
    // int func(vector<int> &arr, int i, int j){
    //     if(i==j) return 0;
        
    //     int mini=1e9;
        
    //     for(int k=i;k<j;k++){
    //         int steps = (arr[i-1]*arr[k]*arr[j]) + func(arr,i,k) + func(arr,k+1,j);
    //         if(steps<mini)
    //             mini = min(mini,steps);
    //     }
    //     return mini;
    // }
  
    int matrixMultiplication(vector<int> &arr) {
        // code here
        int n = arr.size();
        if(n<=2) return 0;
        vector<vector<int>> dp(n,vector<int>(n,-1));
        // the first row is also all zeros as when i=0 we cannot have a valid partition similarly for j = 0
        for(int i=0;i<n;i++) dp[i][i] = 0;
        // for(int i=0;i<n;i++) dp[i][0] = 0;
        // for(int i=0;i<n;i++) dp[0][i]=0;
        
        int mini = 1e9;
        for(int i=n-1;i>=1;i--){
            for(int j=i+1;j<n;j++){
                int mini=1e9;
                
                for(int k=i;k<j;k++){
                    int steps = (arr[i-1]*arr[k]*arr[j]) + dp[i][k] + dp[k+1][j];
                    if(steps<mini)
                        mini = min(mini,steps);
                }
                dp[i][j] = mini;
            }
        }
        return dp[1][n-1];
        //initialise all same [i][j] = 0
        // for(int i=0;i<n;i++) dp[i][i] = 0;
        
        
        
        // //first we need to calculate for the whole array
        // int j = arr.size()-1;
        // int i = 1;
        // return func(arr,i,j);
        
    }
};