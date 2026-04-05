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
        
    def dfs(self, src, visited, adj, curr_li):
        visited[src] = True
        curr_li.append(src)
        for nbr in adj[src]:
            if not visited[nbr]:
                self.dfs(nbr, visited, adj, curr_li)
                
        return curr_li


    # Time complexity : O(E) + O(V+E) [finishing time] + O(V+E ) [dfs on reverse adj]
    # Total TC : O(V+E)
    # Space complexity : O(E) + O(2V)
    # Total SC = O(2E+2V)
    def kosaraju(self, V, edges):
        # code here
        
        if V == 0:
            return 0
        if not edges:
            return V
            
        # form the adj list
        
        adj = defaultdict(list)     # Space : O(E)
        reverse_adj = defaultdict(list)     # Space : O(E)
        
        # Time Complexity : O(E)
        for u,v in edges:
            adj[u].append(v)
            reverse_adj[v].append(u)
        
        
        # step 1 : sort all the vertices according to finishing time
        visited = [False] * V   # Space : O(V)
        st = []     # Space : O(V)
        for i in range(V):
            if not visited[i]:
                self.finishingTime(i, adj, visited, st)
                
        
        # now start the dfs again in the reversed graph and count the SCC
        visited = [False] * V 
        scc = 0
        scc_paths = []
        
        # O(V+E)
        while st:
            src = st.pop()
            # curr_li.append(src)
            if not visited[src]:
                curr_li = []
                # Time : (V+E)
                curr_li = self.dfs(src, visited, reverse_adj, curr_li)
                # print(visited)
                scc +=1
                scc_paths.append(curr_li)
                
                
        # print(scc_paths)
        return scc
            