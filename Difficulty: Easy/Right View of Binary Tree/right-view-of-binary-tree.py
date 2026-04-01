'''
class Node:
    def __init__(self, val):
        self.data = val
        self.left = None
        self.right = None
'''

from collections import deque

class Solution:
    def rightView(self, root):
        # code here
        if root is None:
            return []
            
        if not root.left and not root.right:
            return [root.data]
            
        
        ans = [] 
        q = deque()
        q.append(root)
        
        # level 0 will always have root
        # ans.append(root.data)
        
        while q:
            
            size = len(q)
            
            temp_q = deque()
            node = q[-1]
            
            ans.append(node.data)
            # q.append(node)
            
            for i in range(size):
                node = q.popleft()
                
                if node.left:
                    temp_q.append(node.left)
                if node.right:
                    temp_q.append(node.right)
                    
            
            # print(temp_q)
            q.extend(temp_q)    
            
        return ans    
        
        
        
        