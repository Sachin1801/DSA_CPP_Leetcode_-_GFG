
from collections import defaultdict, deque

class Solution:
    def findOrder(self, words):
        # code here
        if not words:
            return ""
            
        
        # step 1 : collect all unique characters 
        unique = set()
        for w in words:
            for ch in w:
                unique.add(ch)
        
        adj = defaultdict(list)
        indegree = {ch : 0 for ch in unique}
        # print(indegree)
        n = len(words)
        
        for i in range(n-1):
            curr = words[i]
            nxt = words[i+1]
            n1 = len(curr)
            n2 = len(nxt)
                
            x = 0
            while x < n1 and x < n2 and curr[x] == nxt[x]:
                x+=1
                
            if x < n1 and x < n2:
                u = curr[x]
                v = nxt[x]
                
                # avoid duplicate edges 
                if v not in adj[u]:
                    adj[u].append(v)
                    indegree[v] +=1
            else:
                if n1 > n2:
                    return ""
                
            
        q = deque([ch for ch in unique if indegree[ch] == 0])
        
        if not q and unique:
            return ""
            
        order_str = []
        
        while q:
            c = q.popleft()
            order_str.append(c)
            
            # check all its nbrs and reduce indegree
            for nbr in adj[c]:
                indegree[nbr] -= 1
                if indegree[nbr] == 0:
                    q.append(nbr)
                    
        
        if len(order_str) != len(unique):
            return ""
        
        return "".join(order_str)
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
            
                