//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string postToInfix(string s) {
        // Write your code here
        stack<string> st;
        for(int i=0;i<s.length();i++){
            if((s[i]>='A' and s[i]<='Z') or (s[i]>='a' and s[i]<='z') or (s[i]>='0' and s[i]<='9')){
                st.push(string(1,s[i]));
            }else{
                //operator is at s[i]
                string temp1 = st.top();
                st.pop();
                string temp2 = st.top();
                st.pop();
                string newS= "(" + temp2 + s[i] + temp1 + ")";
                st.push(newS);
            }
        }
        return st.top();
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        string postfix;
        cin >> postfix;
        // char marker; cin >> marker;

        Solution obj;
        cout << obj.postToInfix(postfix) << endl;

        // cout << "~\n";
    
cout << "~" << "\n";
}
    fclose(stdout);

    return 0;
}

// } Driver Code Ends