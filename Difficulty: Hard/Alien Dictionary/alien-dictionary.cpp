//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
    private:
    vector<int> topo_sort(int k, vector<int> Adj[]){
        vector<int> inDegree(k,0);
        queue<int> q;
        for(int i=0;i<k;i++){
            for(auto nbr: Adj[i]){
                inDegree[nbr]++;
            }
        }
        for(int i=0;i<k;i++){
            if(inDegree[i]==0){
                q.push(i);
            }
        }
        vector<int> ans;
        while(!q.empty()){
            int front = q.front();
            ans.push_back(front);
            q.pop();
            for(auto nbr: Adj[front]){
                inDegree[nbr]--;
                if(inDegree[nbr]==0)
                    q.push(nbr);
            }
        }
        return ans;
    }
    
  public:
    string findOrder(vector<string> dict, int k) {
        // code here
        int n = dict.size();
        vector<int> Adj[k];
        
        //compare pairs 
        for(int i=0;i<n-1;i++){
            string s1 = dict[i];
            string s2 = dict[i+1];
            int minlen = min(s1.size(),s2.size());
            //form adj list
            for(int j=0;j<minlen;j++){
                if(s1[j]!=s2[j]){
                    //different characters
                    Adj[s1[j]-'a'].push_back(s2[j]-'a');
                    break;
                }
            }
        }
        
        vector<int> ans = topo_sort(k,Adj);
        string result ="";
        for(auto ch: ans){
            result += char(ch + 'a');
        }
        return result;
        
    }
};


//{ Driver Code Starts.
string order;

bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size())
        return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<string> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        string number;
        while (ss >> number) {
            a.push_back(number);
        }
        int K;
        cin >> K;
        getchar();
        Solution obj;
        string ans = obj.findOrder(a, K);
        order = "";
        for (int i = 0; i < ans.size(); i++)
            order += ans[i];

        string temp[a.size()];
        std::copy(a.begin(), a.end(), temp);
        sort(temp, temp + a.size(), f);

        bool f = true;
        for (int i = 0; i < a.size(); i++)
            if (a[i] != temp[i])
                f = false;

        if (f)
            cout << "true";
        else
            cout << "false";
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends