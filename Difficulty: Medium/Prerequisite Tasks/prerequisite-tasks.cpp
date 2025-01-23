//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool isPossible(int N, int P, vector<pair<int, int> >& prerequisites) {
        // Code here
        vector<int> Adj[N];
        for(auto it: prerequisites){
            Adj[it.second].push_back(it.first);
        }
        
        int inDegree[N]={0};
        for(int i=0;i<N;i++){
            for(auto node: Adj[i]){
                inDegree[node]++;
            }
        }
        queue<int> q;
        for(int i=0;i<N;i++){
            if(inDegree[i]==0) q.push(i);
        }
        
        vector<int> topo;
        while(!q.empty()){
            int front = q.front();
            q.pop();
            topo.push_back(front);
            
            for(auto nbr: Adj[front]){
                inDegree[nbr]--;
                if(inDegree[nbr]==0) q.push(nbr);
            }
        }
        
        if(topo.size()==N) return true;
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, P, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends