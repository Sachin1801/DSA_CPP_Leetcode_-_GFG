
# from collections import deque
from queue import Queue

class Solution:
    
    def bfs(self, adj):
        # code here
        if len(adj) ==0:
            return []
            
        ans = []
        V = len(adj)
        visited = [False] * V
        
        q = Queue()
        # q.append(0)
        # visited[0] = True # mark the initial src as visited
        visited[0] = True
        q.put_nowait(0)
        
        
        while not q.empty():
            u = q.get_nowait()
            ans.append(u)
                    
            # visit all nbrs of the src u
            for nbr in adj[u]:
                if not visited[nbr]:
                    visited[nbr] = True
                    q.put_nowait(nbr)
                            
        return ans