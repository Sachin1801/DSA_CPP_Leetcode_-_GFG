class Solution {
  public:
    int maxProduct(vector<int> &arr) {
        // code here
        if(arr.size()==1){
            return arr[0];
        }
        int max_prod=0, min_prod = 0;
        int ans = INT_MIN;
        for(int i =0; i<arr.size();i++){
            if(arr[i]==0){
                max_prod =0;
                min_prod=0;
                if(max_prod > ans) ans = max(ans,max_prod);
                continue;
            }
            if(max_prod == 0 && min_prod == 0){
                max_prod = min_prod = arr[i];
                if(max_prod > ans) ans = max(ans,max_prod);
            }
            else{
                int tempMin = min_prod;
                int tempMax = max_prod;
                min_prod = min(tempMin * arr[i],min(arr[i], tempMax*arr[i]));
                max_prod = max(tempMax*arr[i],max(tempMin*arr[i],arr[i]));
                
                if(max_prod > ans) ans = max(ans, max_prod);
            }
        }
        return ans;
    }
};