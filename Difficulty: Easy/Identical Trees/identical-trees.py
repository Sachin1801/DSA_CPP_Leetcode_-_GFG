'''
class Node:
    def _init_(self, val):
        self.data = val
        self.right = None
        self.left = None
'''

class Solution:
    def isIdentical(self, r1, r2):
        # code here
        
        def in_order(root, l):
            if root is None:
                return
            
            # go to the left tree
            in_order(root.left, l)
            
            # push the root
            l.append(root.data)
            
            # go to the right tree
            in_order(root.right, l)
            
            return
            
        
        in_order1 = []
        in_order2 = []
        
        in_order(r1, in_order1)
        in_order(r2, in_order2)
        
        if in_order1 == in_order2:
            return True
        return False
        
        
        