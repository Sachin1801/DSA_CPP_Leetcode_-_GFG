class Solution:
    
    def DFS(self, src, visited, ans, adj):
        
        # mark current as true
        visited[src] = True
        # add in the final list
        ans.append(src)
        
        # check all the nbrs in adj
            #go deep in the ones which are unvisited
        for nbr in adj[src]:
            if not visited[nbr]:
                self.DFS(nbr, visited, ans, adj)
                
        return ans
    
    def dfs(self, adj):
        # code here
        V = len(adj)
        if V == 0:
            return []
            
        
        visited = [False] * V
        
        src= 0
        ans = []
        return self.DFS(src, visited, ans,adj)
        