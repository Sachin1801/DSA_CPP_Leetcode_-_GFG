'''
# Node Class:
class Node:
    def _init_(self,val):
        self.data = val
        self.left = None
        self.right = None
'''

from collections import deque

class Solution:
    def maxWidth(self, root):
        #code here
        
        if not root:
            return 0
        
        if not root.left and not root.right:
            return 1
        
        ans = 1
        
        q = deque()
        q.append(root)
        while q:
            size = len(q)
            
            # track the max size of the current level
            ans = max(size, ans)
            
            for i in range(size):
                node = q.popleft()
                
                if node.left:
                    q.append(node.left)
                    
                if node.right:
                    q.append(node.right)
                    
        
        return ans
                