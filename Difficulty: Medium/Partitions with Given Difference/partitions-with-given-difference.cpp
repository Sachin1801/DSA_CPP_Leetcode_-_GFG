//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


#define MOD 1000000009
class Solution {
private:

    int findways(vector<int> &arr, int target){
        int n = arr.size();
        vector<vector<int>> dp(n,vector<int>(target+1,0));
        
        if(arr[0]==0) dp[0][0]=2;
        else dp[0][0]=1;
        if(arr[0]!=0 && arr[0] <=target) dp[0][arr[0]]=1;
        
        for(int ind =1; ind<n;ind++){
            for(int sum =0;sum <=target;sum++){
                int notTake = dp[ind-1][sum];
                int take = 0;
                if(arr[ind]<=sum) take = dp[ind-1][sum-arr[ind]];
                dp[ind][sum]=(take+ notTake)%MOD;
            }
        }
        
        return dp[n-1][target];
    }
    
  public:
    int countPartitions(vector<int>& arr, int d) {
        // Code here
        int totalsum= accumulate(arr.begin(),arr.end(),0);
        if(totalsum - d < 0 || (totalsum - d)%2!=0) return 0;
        
        return findways(arr,(totalsum-d)/2);
    }
};


//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.countPartitions(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends