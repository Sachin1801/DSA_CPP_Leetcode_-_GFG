class Solution {
  public:
    int getMinDiff(vector<int> &arr, int k) {
        // code here
        sort(arr.begin(),arr.end());
        int n = arr.size();
        
        int res = arr[n-1]-arr[0];
        
        for(int i=1;i<arr.size();i++){
            
            if(arr[i] - k <0) continue;
            
            int new_min = min(arr[0]+k, arr[i]-k);
            int new_max = max(arr[n-1]-k,arr[i-1]+k);
            
            res = min(res,new_max - new_min);
            
        }
        return res; 
    }
};