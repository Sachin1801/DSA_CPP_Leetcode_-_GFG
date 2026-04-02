'''
class Node:
    def __init__(self, val):
        self.data = val
        self.left = None
        self.right = None
'''

# O(n) solution is an inorder traversal


class Solution:
    def kthSmallest(self, root, k): 
        # code here
        if not root:
            return -1
        
        inorder = []
            
        def Inorder(root, inorder):
            if not root:
                return -1
            
            Inorder(root.left, inorder)
            inorder.append(root.data)
            
            # we have got the kth element check
            # if len(inorder) == k:
            #     ans = inorder[-1]
            #     return
            
            Inorder(root.right,inorder)
        
        
        Inorder(root,inorder)
        # if k > len(inorder):
        #     return -1
        
        return -1 if k > len(inorder) else inorder[k-1]