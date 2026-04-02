#User function Template for python3

class Node:
    def __init__(self, val):
        self.data = val
        self.left = None
        self.right = None

class Solution:
    def flatten(self, root):
        #code here
        prev = None
        if not root:
            return None
        
        def flattenTree(node):
            nonlocal prev
            if not node:
                return
            
            # first go right
            flattenTree(node.right)
            # 2. go to left
            flattenTree(node.left)
            
            # mark node's right as prev
            node.right = prev
            # mark node's left as null
            node.left = None
            # update the prev to be the node
            prev = node 
        
        flattenTree(root)
        return root
            
        
        