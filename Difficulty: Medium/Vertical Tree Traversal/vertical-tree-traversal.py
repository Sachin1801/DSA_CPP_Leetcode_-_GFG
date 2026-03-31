'''
class Node:
    def __init__(self, val):
        self.data = val
        self.left = None
        self.right = None
'''

from collections import defaultdict, deque

class Solution:
    def verticalOrder(self, root): 
        # code here
        if not root:
            return []
            
        
        d = defaultdict(list)
        dq = deque([(root,0)])
        
        while dq:
            node, col = dq.popleft()
            d[col].append(node.data)
            
            if node.left:
                dq.append((node.left,col-1))
            if node.right:
                dq.append((node.right, col+1))
                
        return [ d[k] for k in sorted(d)]