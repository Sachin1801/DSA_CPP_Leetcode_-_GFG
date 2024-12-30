//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#include<deque>
class Solution {
  public:
    void print_divisors(int n) {
        // Code here.
        vector<int> ans;
        if(n==1){
          cout<<1;  
          return;
        }  
        for(int i=1;i<=sqrt(n);i++){
            if((n%i)==0){
                ans.push_back(i);
            }
        }
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
            if(n/ans[i]!=ans[i])
                ans[i]=n/ans[i];
            else
                ans[i]=-1;
        }
        for(int i=ans.size()-1;i>=0;i--){
            if(ans[i]!=-1)
                cout<<ans[i]<<" ";
        }
        return;
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        Solution ob;
        ob.print_divisors(n);
        cout << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends