

from collections import defaultdict, deque

class Solution:
    
    def bfs(self, src, visited, adjList, ans):
        visited[src] = True
        
        q = deque()
        q.append(src)
        curr_li = []
        while q:
            u = q.pop()
            curr_li.append(u)
            for nbr in adjList[u]:
                if not visited[nbr]:
                    visited[nbr] = True
                    q.append(nbr)
        
        ans.append(curr_li)
        return
    
    def getComponents(self, V, edges):
        # code here
        
        adjList = defaultdict(list)
        
        # form the adj list
        for edge in edges:
            u = edge[0]
            v = edge[1]
            adjList[u].append(v)
            adjList[v].append(u)
            
        visited = [False] * V
        
        ans = []
        
        for i in range(V):
            if not visited[i]:
                self.bfs(i, visited, adjList, ans)
                
        return ans