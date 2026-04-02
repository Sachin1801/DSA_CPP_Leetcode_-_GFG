'''
class Node:
    def __init__(self, val):
        self.data = val
        self.left = None
        self.right = None
'''

class Solution:
    
    
    def findLCA(self, root, n1,n2):
        if not root:
            return None
        
        # Case 1: root is less than both n1 and n2
            # solution is on the right of the root
        if root.data < n1 and root.data < n2:
            return self.findLCA(root.right, n1, n2)
        
        # Case 2 : root is more than both n1 and n2
            # solution is on the left subree
        if root.data > n1 and root.data > n2:
            return self.findLCA(root.left, n1, n2)
            
        # Case 3: root is == n1 or ==n2
            # this is the lca itself
            # return this node
        if root.data >= n1 and root.data <= n2:
            return root
    
    def LCA(self, root, n1, n2):
        # code here
        if not root:
            return -1
            
        if n1.data > n2.data:
            temp = n2
            n2 = n1
            n1 = temp
        
        if root.data == n1.data:
            return n1
        if root.data == n2.data:
            return n2
        
        
        
        return self.findLCA(root, n1.data, n2.data)
        