'''
class Node:
    def __init__(self, x):
        self.data = x
        self.left = None
        self.right = None
'''        
        

class Solution:
    def buildTree(self, inorder, postorder):
        #code here
        
        n = len(postorder)
        if n == 0:
            return []
            
        self.post_idx = n-1
        
        # form the inorder map
        inorder_map = {val:i for i, val in enumerate(inorder)} # O(1) lookup
        
        def helper(st, end):
            if st > end:
                return None
            
            root_val = postorder[self.post_idx]
            self.post_idx -= 1
            node = Node(root_val)
            
            curr_idx = inorder_map[root_val]
            
            node.right = helper(curr_idx+1, end)
            node.left = helper(st,curr_idx-1)
            return node
        
        
        
        return helper(0,n-1)