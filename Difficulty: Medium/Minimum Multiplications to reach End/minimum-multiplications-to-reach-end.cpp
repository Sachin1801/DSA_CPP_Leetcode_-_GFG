//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

#define MOD 100000

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        if(start==end)
            return 0;
        vector<int> dist(100000,INT_MAX);
        dist[start]=0;
        queue<pair<int,int>> q;
        q.push({start,0});
        while(!q.empty()){
            auto top = q.front();
            q.pop();
            int val = top.first;
            int steps= top.second;
            for(int i=0;i<arr.size();i++){
                int newval = (val*arr[i])%MOD;
                if(steps + 1 < dist[newval]){
                    dist[newval]=steps+1;
                    if(newval == end)
                        return steps+1;
                    q.push({newval,steps+1});
                }
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    
cout << "~" << "\n";
}
}

// } Driver Code Ends