'''
class Node:
    def __init__(self, val):
        self.data = val
        self.left = None
        self.right = None
'''
from collections import deque

class Solution:
    def zigZagTraversal(self, root):
        # code here
        
        ans = []
        level = 1
        dq = deque()
        
        dq.append(root)
        
        while dq:
            # Even level
            if level % 2 ==0:
                size = len(dq)
                li = []
                while size > 0:
                    top = dq.popleft()
                    li.append(top.data)
                    if top.left:
                        dq.append(top.left)
                    if top.right:
                        dq.append(top.right)
                        
                    size -= 1
                    
                li.reverse()
                
                ans.extend(li)
                level += 1
                
            # odd level    
            else:
                size = len(dq)
                while size > 0:
                    top = dq.popleft()
                    ans.append(top.data)
                    
                    if top.left:
                        dq.append(top.left)
                    if top.right:
                        dq.append(top.right)
                    size -= 1
                
                level +=1
                
        
        return ans