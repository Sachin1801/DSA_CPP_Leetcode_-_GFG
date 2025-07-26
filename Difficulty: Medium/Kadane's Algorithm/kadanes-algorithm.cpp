class Solution {
  public:
    int maxSubarraySum(vector<int> &arr) {
        // Code here
        int max_sum = 0;
        int curr=0;
        for(int i =0;i<arr.size();i++){
            curr += arr[i];
            if(curr < 0){
                curr =0;
            }else{
                max_sum = max(max_sum, curr);
            }
        }
        return max_sum== 0 ? *max_element(arr.begin(),arr.end()) : max_sum ;
    }
};