//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:

    vector<int> replaceWithRank(vector<int> &arr, int N){
        
        auto cmp = [](pair<int,int> p1, pair<int,int> p2){
            return p1.first > p2.first;
        };
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> q(cmp);
        
        for(int i=0;i<arr.size();i++){
            q.push({arr[i],i});
        }
        int rank = 0;
        int prevval = -1;
        while(!q.empty()){
            auto curr = q.top();
            q.pop();
            if(prevval == curr.first)
                arr[curr.second]= rank;
            else{
                rank++;
                arr[curr.second]= rank;
                prevval = curr.first;
            }
        }
        return arr;
    }

};


//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while(t--){
        //Input

       int n; cin >> n;
       vector<int> vec(n);
       for(int i = 0;i<n;i++) cin >> vec[i];

        Solution obj;
        vector<int> ans = obj.replaceWithRank(vec,n);
        for(int i = 0;i<n;i++) cout << ans[i] << " ";
        cout << endl;
        

        
        // cout << "~\n";
    
cout << "~" << "\n";
}
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends