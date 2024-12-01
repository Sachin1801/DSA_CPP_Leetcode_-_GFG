class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int low =0,high = arr.size()-1;
        while(low<=high){
            int mid = (low+high)/2;
            int missingvaluescnt = arr[mid]-(mid+1);
            if(missingvaluescnt < k){
                low = mid + 1;
            }else{
                high = high - 1;
            }
        }
        return low + k ;
    }
};