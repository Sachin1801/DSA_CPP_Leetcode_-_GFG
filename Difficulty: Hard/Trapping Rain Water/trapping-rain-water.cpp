class Solution {
  public:
    int maxWater(vector<int> &arr) {
        // code here
        int n = arr.size();
        vector<int> lmax(n,0);
        vector<int> rmax(n,0);
        
        int currmax = 0;
        for(int i =0;i<n;i++){
            if(arr[i]> currmax) {
                currmax = max(arr[i], currmax);
            }
            lmax[i]=currmax;
        }
        currmax = 0;
        for(int i=n-1;i>=0;i--){
            if(arr[i] > currmax ){
                currmax = max(currmax, arr[i]);
            }
            rmax[i]=currmax;
        }
        
        int trapped_rain=0;
        for(int i =0;i<n;i++){
            trapped_rain += min(lmax[i],rmax[i]) - arr[i];
        }
        return trapped_rain;
    }
};