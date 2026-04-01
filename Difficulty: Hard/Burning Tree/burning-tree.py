'''
class Node:

    def __init__(self, val):
        self.data = val
        self.left = None
        self.right = None
'''

from collections import defaultdict, deque

class Solution:
    def minTime(self, root, target):
        # code here
        if not root:
            return 0
        
        if not root.left and not root.right and root.data == target:
            return 0
        
        # form the adjlist
        d = defaultdict(list)
        q = deque()
        q.append(root)
        target_node = None
        
        while q:
            node = q.popleft()
            if node.data == target:
                target_node = node
            if node.left:
                d[node].append(node.left)
                d[node.left].append(node)
                q.append(node.left)
            if node.right:
                d[node].append(node.right)
                d[node.right].append(node)
                q.append(node.right)
            
        
        q.append(target_node)
        ans = 0
        visited = {target_node}
        
        while q:
            size = len(q)
            for _ in range(size):
                node = q.popleft()
                
                for nbr in d[node]:
                    if nbr not in visited:
                        visited.add(nbr)
                        q.append(nbr)
            ans += 1
                
        return ans-1