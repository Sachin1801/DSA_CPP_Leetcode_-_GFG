//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
    private:
        bool f(int i, int target, vector<int> &arr, vector<vector<int>> &dp){
            if(target==0) return dp[i][target]=1;
            if(i==0) return dp[i][target] = arr[0]==target;
            if(dp[i][target]!=-1) return dp[i][target];
            bool notTake = f(i-1,target,arr,dp);
            
            bool Take=false;
            if(target - arr[i] >= 0) Take = f(i-1,target-arr[i],arr,dp);
            
            return dp[i][target]= Take|notTake;
        }
    
  public:
    bool isSubsetSum(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        vector<vector<int>> dp(n,vector<int>(target+1,-1));
        return f(n-1,target,arr,dp);
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int sum;
        cin >> sum;
        cin.ignore();

        Solution ob;
        if (ob.isSubsetSum(arr, sum))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends