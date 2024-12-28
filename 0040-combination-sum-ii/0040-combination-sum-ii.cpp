class Solution {
private:

void calculate(vector<int> &arr, int target, int idx, vector<int> &ds, vector<vector<int>> &ans ){
    if(target==0){
        ans.push_back(ds);
        return;
    }
    for(int i =idx ;i < arr.size();i++){
        if( i > idx && arr[i] == arr[i-1]) continue;
        if(arr[i]>target) break;

        ds.push_back(arr[i]);
        calculate(arr,target-arr[i],i+1,ds,ans);
        ds.pop_back();
    }
}

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> ds;
        vector<vector<int>> ans ;
        sort(candidates.begin(),candidates.end());
        calculate(candidates, target, 0, ds,ans);
        return ans;
    }
};