class Solution {
  public:
    // Function to find all elements in array that appear more than n/k times.
    int countOccurence(vector<int>& arr, int k) {
        // Your code here
        int ans = 0;
        unordered_map<int,int> m;
        int n = arr.size();
        for(int i =0; i<n;i++){
            m[arr[i]]++;
        }
        for(const auto &[key,val]:m){
            if(val > n/k){
                ans++;   
            }
        }
        return ans;
    }
};