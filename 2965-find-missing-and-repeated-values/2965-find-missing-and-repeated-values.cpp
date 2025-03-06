class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        long long s = n*n;
        vector<long long> val(s+1,-1);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                val[grid[i][j]]++;
            }
        }
        vector<int> ans(2);
        for(int i=1;i<val.size();i++){
            if(val[i]==-1){
                ans[1]=i;
            }
            if(val[i]==1) ans[0]=i;
        }
        return ans;
    }
};