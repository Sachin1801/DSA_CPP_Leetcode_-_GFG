class Solution {
  public:
    vector<int> getLIS(vector<int>& arr) {
        // Code here
        
        int n = arr.size();
        if(n==1)
            return arr;
            
        vector<int> dp(n,1);
        vector<int> parent(n,-1);
        
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(arr[i] > arr[j]){
                    if(dp[j] + 1 > dp[i] ){
                        dp[i] = max(dp[i],1 + dp[j]);
                        parent[i] = j;
                    }
                }
            }
        }
        
        vector<int> ans;
        //we get the index where the LIS end
        
        auto it = max_element(dp.begin(), dp.end());
        int idx = it - dp.begin();
        
        while(idx != -1){
            ans.push_back(arr[idx]);
            idx = parent[idx];
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};