class Solution {
private:

void dfs(string &s, int src, vector<int> &idx, set<int> &visited, vector<char> &chars){
    visited.insert(src);
    idx.push_back(src);
    chars.push_back(s[src]);

    for(auto nbr: adj[src]){
        if(visited.count(nbr)==0) dfs(s,nbr,idx,visited,chars);
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
        set<int> visited;
        for(int i=0;i<s.size();i++){
            if(visited.count(i)==0){
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