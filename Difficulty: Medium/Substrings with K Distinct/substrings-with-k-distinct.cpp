//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {

    
  public:
    int countSubstr(string& s, int k) {
        // code here.
        int ans =0 ;
        int n = s.length();
        int freq[26]={0};
        for(int i=0;i<n;i++){
            int dist_cnt=0;
            memset(freq,0,sizeof(freq));
            for(int j=i;j<n;j++){
                //if this is a new charactrer for the substring
                if(freq[s[j]-'a']==0){
                    dist_cnt++;
                }
                freq[s[j]-'a']++;
                if(dist_cnt==k){
                    ans++;
                }
                if(dist_cnt>k){
                    break;
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.countSubstr(s, k) << endl;

        cout << "~"
             << "\n";
    }
}
// } Driver Code Ends