//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

#define MAXN 200001
vector<int> spf(MAXN+1, 1);

class Solution {
public:
    void sieve() {  // Fixed parameter type
        // Mark non-prime numbers in the sieve
        spf[0]=0;
        for(int i=2;i<=MAXN;i++){
            if(spf[i]==1){
                for(int j=i;j<=MAXN;j+=i){
                    if(spf[j]==1)
                        spf[j]=i;
                }
            }
        }
    }
    
    vector<int> findPrimeFactors(int x) {
        vector<int> ans;
        
        // First run the sieve
        while(x!=1){
            ans.push_back(spf[x]);
            x = x/spf[x];
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        int n;
        cin >> n;

        Solution obj;
        obj.sieve();
        vector<int> vec = obj.findPrimeFactors(n);
        for (int i = 0; i < vec.size(); i++) {
            cout << vec[i] << " ";
        }
        cout << endl;

        // cout << "~\n";
    
cout << "~" << "\n";
}
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends