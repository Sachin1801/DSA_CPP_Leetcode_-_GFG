'''
class Node:
    def __init__(self, val):
        self.data = val
        self.left = None
        self.right = None
'''

from collections import deque

class Solution:
    
    # def __init__(self):
    
    def serialize(self, root):
        #code here
        if not root:
            return
        
        middle_str = []
        q = deque()
        q.append(root)
        
        while q:
            node = q.popleft()
            if not node:
                middle_str.append('#')
                continue
            else:
                middle_str.append(str(node.data))
            
            # skip if the current node is a null node:
            if not node:
                continue
            else:
                # if left node
                if node.left:
                    q.append(node.left)
                else:
                    q.append(None)
                # check for right node: enter in queue and string
                if node.right:
                    q.append(node.right)
                else:
                    q.append(None)
        return middle_str            

    def deSerialize(self, arr):
        #code here
        if not arr or arr[0] == '#':
            return None
        
        root = Node(int(arr[0]))
        q = deque([root])
        i = 1
        
        while q and i < len(arr):
            node = q.popleft()
            
            # left child 
            if arr[i] != '#':
                node.left = Node(int(arr[i]))
                q.append(node.left)
            i+=1
            
            if i < len(arr) and arr[i] !='#':
                node.right = Node(int(arr[i]))
                q.append(node.right)
            i+=1
            
        return root
            
            
            
            
            
            
            
            
            
        
            
    