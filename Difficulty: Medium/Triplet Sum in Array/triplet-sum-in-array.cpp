class Solution {
  public:
    bool hasTripletSum(vector<int> &arr, int target) {
        // Code Here
        int csum =0;
        int n  = arr.size();
        sort(arr.begin(),arr.end());
        for(int i =0;i<n-2;i++){
            csum = arr[i];
            int rem = target - csum;
            int j = i+1,k=n-1;
            while(j<k){
                if(arr[j] + arr[k] == rem) return true;
                else if(arr[j]+arr[k] < rem ){
                    j++;
                }else{
                    k--;
                }
            }
        }
        return false;
    }
};