from collections import defaultdict

class Solution:
    
    def finishingTime(self, src, adj, visited, st):
        
        visited[src] = True
        
        # visit all nbrs if not visited
        for nbr in adj[src]:
            if not visited[nbr]:
                self.finishingTime(nbr, adj, visited, st)
        
        st.append(src)
        return st
        
    def dfs(self, src, visited, adj):
        visited[src] = True
        for nbr in adj[src]:
            if not visited[nbr]:
                self.dfs(nbr, visited, adj)

    def kosaraju(self, V, edges):
        # code here
        
        if V == 0:
            return 0
        if not edges:
            return V
            
        # form the adj list
        adj = defaultdict(list)
        reverse_adj = defaultdict(list)
        
        for edge in edges:
            u = edge[0]
            v = edge[1]
            
            adj[u].append(v)
            reverse_adj[v].append(u)
        
        
        # step 1 : sort all the vertices according to finishing time
        visited = [False] * V
        st = []
        for i in range(V):
            if not visited[i]:
                self.finishingTime(i, adj, visited, st)
                
        
        # now start the dfs again in the reversed graph and count the SCC
        visited = [False] * V 
        scc = 0
        while st:
            src = st.pop()
            if not visited[src]:
                self.dfs(src, visited, reverse_adj)
                scc +=1
                
                
        return scc
            