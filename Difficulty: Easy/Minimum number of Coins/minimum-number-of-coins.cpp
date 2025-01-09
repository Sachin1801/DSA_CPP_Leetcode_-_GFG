//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> minPartition(int sum)
    {
        // code here
        // Your code goes here
        vector<int> coins={1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
        if(sum==0)
            return {};
        vector<int> ans;
        int i = 9;
        int my_sum = 0;
        while(i>=0 and my_sum <=sum){
            while(coins[i]+my_sum <= sum){
                my_sum += coins[i];
                ans.push_back(coins[i]);
            }
            if(my_sum == sum)
                return ans;
            i--;
        }
        return {};
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> numbers = ob.minPartition(N);
        for(auto u: numbers)
            cout<<u<<" ";
        cout<<"\n";
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends