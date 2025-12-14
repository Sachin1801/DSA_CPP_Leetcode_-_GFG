// Last updated: 12/14/2025, 4:15:14 PM
class Solution {
public:
    // int bfs(vector<vector<int>> &adjList, vector<int> &online, int node,int &minId){
    //     queue<int> q;
    //     q.push(node);
    //     vector<bool> visited(online.size(),false);
    //     while(!q.empty()){
    //         int u = q.front();
    //         q.pop();
    //         visited[u]=true;
    //         if(online[u] == 1){
    //             if(u < minId ) minId = u;
    //         }
    //         for(auto &val:adjList[u]){
    //             if(!visited[val]){
    //                 visited[val]=true;
    //                 q.push(val);
    //             }
    //         }
    //     }
    //     return minId;
    // }

    void dfs(int u, int compId, vector<vector<int>> &adjList, vector<int> &component, vector<bool> &visited){
        visited[u]=true;
        component[u]=compId;
        for(auto &v: adjList[u]){
            if(!visited[v])
                dfs(v,compId, adjList,component,visited);
        }
        return;
    }

    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        
        vector<vector<int>> adjList(c+1);

        //form the adjacency matrix
        for(auto vec: connections ){
            adjList[vec[0]].push_back(vec[1]);
            adjList[vec[1]].push_back(vec[0]);
        }

        vector<int> component(c+1,-1);
        int compId = 1;
        vector<bool> visited(c+1, false);
        for(int i=0;i<adjList.size();i++){
            if(!visited[i]){
                dfs(i,compId,adjList, component, visited);
                compId++;
            }
        }

        map<int,set<int>> m;
        for(int i=0;i<component.size();i++){
            if(component[i]!=-1){
                m[component[i]].insert(i);
            }
        }

        //all online in the start
        vector<int> online(c+1,1);
        online[0]=-1;
        vector<int> ans;
        for(auto query: queries){
            int operation = query[0];
            int node = query[1];

            if(operation == 1){
                //maintenance check
                if(online[node]==1) ans.push_back(node);
                else{
                    //find the componentID of the node
                    int id = component[node];
                    if(id != -1 && m[id].size() > 0){
                        ans.push_back(*m[id].begin());
                    }else{
                        ans.push_back(-1);
                    }
                }
            }else{
                int id = component[node];
                m[id].erase(node);
                online[node]=0;

            }
        }
        return ans;
    }
};