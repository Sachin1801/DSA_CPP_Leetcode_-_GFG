class Solution {
  public:
    int smallestSubWithSum(int x, vector<int>& arr) {
        // Your code goes here
        int ans = INT_MAX;
        int i =0,j=0;
        int currSum = 0;
        int n = arr.size();
        
        while(j<n){
            currSum += arr[j];
            if(currSum > x){
                ans = min(ans, j-i+1);
                while(i < n && i<=j){
                    if(currSum - arr[i] > x){
                        currSum -= arr[i];
                        i++;
                        ans = min(ans, j-i+1);
                    }
                    else{
                        j++;
                        break;
                    }
                }
            }else{
                j++;
            }
        }
        return ans == INT_MAX ? 0:ans;
    }
};