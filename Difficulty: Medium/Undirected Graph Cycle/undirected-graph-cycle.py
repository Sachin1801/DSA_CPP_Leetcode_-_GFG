
from collections import defaultdict

class Solution:
    
    def dfs(self, src, prev, adj, visited):
        visited[src] = True
        isCycle = False
        # we will check for all its nbrs
        for nbr in adj[src]:
            if not visited[nbr]:
                isCycle =  self.dfs(nbr, src, adj, visited)
                if isCycle:
                    break
            elif visited[nbr] and prev != nbr:
                isCycle = True
                break
                
        return isCycle
    
	def isCycle(self, V, edges):
	    # form adj list
	    adj = defaultdict(list)
	    
	    
	    for edge in edges:
	        u = edge[0]
	        v = edge[1]
	        
	        adj[u].append(v)
	        adj[v].append(u)
	        
	    
	   # // start from any vertex
	    src = 0
	    prev = -1
	    
	    visited = [False] * V
	    
	    for v in range(V):
	        if not visited[v]:
	            if self.dfs(v, prev, adj, visited):
	                return True
	   
	    return False
	            
		
	   
	   