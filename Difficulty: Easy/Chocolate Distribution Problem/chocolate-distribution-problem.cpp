class Solution {
  public:
    int findMinDiff(vector<int>& a, int m) {
        // code here
        sort(a.begin(),a.end());
        int n = a.size();
        int i = 0, j= m-1;
        if(m==n) return a[n-1] - a[0];
        
        int ans = INT_MAX;
        while(j<n){
            ans  = min(ans, a[j]-a[i]);
            j++;
            i++;
        }
        return ans;
        
    }
};