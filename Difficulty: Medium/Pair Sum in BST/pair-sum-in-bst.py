'''
# Tree Node
class Node:
    def __init__(self, val):
        self.right = None
        self.data = val
        self.left = None

'''

class Solution:
    def findTarget(self, root, target): 
        # your code here.
        if not root:
            return False
        
        def getInorder(root):
            
            inorder = []
            inorder_set = set()
            curr = root
            
            while curr:
                
                # Case 1 : if not left
                    # 1) : push to inorder
                    # 2) move to right -> curr = curr.right
                if not curr.left:
                    inorder.append(curr.data)
                    inorder_set.add(curr.data)
                    curr = curr.right
                else:
                    prev = curr.left
                    while prev.right and prev.right != curr:
                        prev = prev.right
                    
                    if not prev.right:
                        prev.right = curr
                        curr = curr.left
                    else:
                        prev.right = None
                        inorder.append(curr.data)
                        inorder_set.add(curr.data)
                        curr = curr.right
                
            
            return inorder, inorder_set
        
        inorder, inorder_set = getInorder(root)
        
        n = len(inorder)
        for i in range(n-1):
            var_1 = inorder[i]
            needed = target - var_1
            
            # check if we have the needed value in set
            if needed in inorder_set:
                return True
        
        return False