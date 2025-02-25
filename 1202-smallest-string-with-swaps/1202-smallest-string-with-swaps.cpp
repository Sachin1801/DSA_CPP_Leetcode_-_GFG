class Solution {
private:

void dfs(string &s, int src, vector<int> &idx, vector<bool> &visited, vector<char> &chars){
    visited[src]=true;
    idx.push_back(src);
    chars.push_back(s[src]);

    for(auto nbr: adj[src]){
        if(!visited[nbr]) dfs(s,nbr,idx,visited,chars);
    }
    return;
}

public:
vector<vector<int>> adj;
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        adj = vector<vector<int>> (s.size());

        for(auto p: pairs){
            adj[p[0]].push_back(p[1]);
            adj[p[1]].push_back(p[0]);
        }
        vector<bool> visited(s.size(),false);
        for(int i=0;i<s.size();i++){
            if(!visited[i]){
                vector<int> idx;
                vector<char> chars;
                dfs(s,i,idx,visited,chars);
                sort(idx.begin(),idx.end());
                sort(chars.begin(),chars.end());
                for(int j=0;j<chars.size();j++){
                    s[idx[j]]=chars[j];
                }
            }
        }
        return s;

    }
};