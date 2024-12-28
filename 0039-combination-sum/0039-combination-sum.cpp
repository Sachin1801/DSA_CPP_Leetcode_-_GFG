class Solution {
private:
    vector<vector<int> > ans ;

void calculate(vector<int> &arr, int target, int idx, vector<int> &ds){
    if(idx == arr.size()){
        if(target==0){
            ans.push_back(ds);
            return;
        }else{
            return;
        }
    }
    if(arr[idx] <= target){
        ds.push_back(arr[idx]);
        calculate(arr,target-arr[idx],idx, ds);
        ds.pop_back();
    }
    calculate(arr,target,idx+1, ds);
}

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> ds;
        calculate(candidates, target, 0, ds);
        return ans;
    }
};