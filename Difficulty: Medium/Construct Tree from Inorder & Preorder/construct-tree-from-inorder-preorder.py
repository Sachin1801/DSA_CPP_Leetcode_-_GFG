'''
# Node class
class Node:
    def __init__(self, val):
        self.data = val
        self.right = None
        self.left = None

'''

class Solution:
    
    def buildTree(self, inorder, preorder):
        # code here
        n = len(preorder)
        if n == 0:
            return []
        
        self.pre_idx = 0
        inorder_map = {val: i for i, val in enumerate(inorder)} # O(1) lookup
        
        def helper(st, end):
            if st > end:
                return None
                
            root_val = preorder[self.pre_idx]
            self.pre_idx +=1
            
            # form the current node
            node = Node(root_val)
            
            # find the idx for the val in the inorder
            mid = inorder_map[root_val]
            node.left = helper(st, mid-1)
            node.right = helper(mid+1, end)
            return node
            
        
        return helper(0,n-1)
        
        
        