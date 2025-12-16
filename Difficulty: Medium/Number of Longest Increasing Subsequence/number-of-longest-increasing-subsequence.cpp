class Solution {
  public:
    int numberofLIS(vector<int>& arr) {
        // Code here
        int n = arr.size();
        if(n==1)
            return 1;
    
        vector<int> dp(n,1);
        vector<int> cnt(n,1);
        
        for(int i=1;i<n;i++){
            for(int j = 0;j<i;j++){
                //we found the next element in the increasing subsequence
                if(arr[i] > arr[j] && dp[j] + 1 >= dp[i] ){
                    if(dp[j] + 1 > dp[i]){
                        cnt[i] = cnt[j];
                    }else{
                        cnt[i]+=cnt[j];
                    }
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }
        }
        
        int maxCnt = *max_element(dp.begin(),dp.end());
        
        // count how many have the same LIS length, store idx
        stack<int> st;
        for(int i=0;i<n;i++){
            if(dp[i]== maxCnt) st.push(i);
        }
        int ans =0;
        while(!st.empty()){
            int topIdx = st.top();
            st.pop();
            
            ans += cnt[topIdx];
        }
        return ans;
    }
};