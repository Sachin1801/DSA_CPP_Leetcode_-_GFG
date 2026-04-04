
from collections import defaultdict
from queue import Queue

class Solution:
    
    def bfs(self, curr, visited, adj):
        q = Queue()
        q.put(curr)
        
        color = [-1] * len(visited)
        color[curr] = 1
        
        visited[curr]= True
        
        while not q.empty():
            src = q.get()
            
            # check for all of its nbrs, that if any of them as the same color as src
            for nbr in adj[src]:
                # not visited
                if color[nbr] == -1:
                    color[nbr] = 1 if color[src] == 0 else 0
                    visited[nbr] = True
                    q.put(nbr)
                elif color[nbr] == color[src]:
                    return False
                    
        return True
    
    def isBipartite(self, V, edges):
        adj = defaultdict(list)
        # form the adj list
        #  Time complexity: O(E)
        for edge in edges:
            u = edge[0]
            v = edge[1]
            adj[u].append(v)
            adj[v].append(u)
        
        visited = [False] * V
        for i in range(V):
            if not visited[i]:
                if not self.bfs(i,visited, adj):
                    return False
                    
        return True
            
        