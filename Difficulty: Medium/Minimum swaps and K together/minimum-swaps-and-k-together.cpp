// Final function implementation
class Solution {
  public:
    int minSwap(vector<int>& arr, int k) {
        // code here
        int swaps = 0;
        int n = arr.size();
        
        queue<int> big;
        queue<int> small;
        
        for(int i =0;i<n;i++){
            if(arr[i] <= k && !big.empty()){
                small.push(i);
            }
            if(arr[i]> k){
                big.push(i);
            }
            
            if(!small.empty() && !big.empty()){
                int s_idx = small.front();
                int b_idx = big.front();
                small.pop();
                big.pop();
                swaps++;
                swap(arr[s_idx], arr[b_idx]);
                big.push(s_idx);
            }
        }
        return swaps;
    }
};
