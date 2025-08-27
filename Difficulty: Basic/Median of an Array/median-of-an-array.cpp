class Solution {
  public:
    double findMedian(vector<int> &arr) {
        // code here.
        sort(arr.begin(),arr.end());
        if(arr.size() == 1) return arr[0];
        
        int low = 0, high = arr.size()-1;
        int mid = low + ( high - low)/2;
        if(arr.size() % 2 == 0 ){
            return double((double(arr[mid]) + double(arr[mid+1]))/2.00);
        }
        return arr[mid];
        
    }
};