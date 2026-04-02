'''
class Node:
    def __init__(self, val):
        self.data = val
        self.left = None
        self.right = None
'''

class Solution:
    def delNode(self, root, x):
        #code here 
        
        if not root:
            return root
            
        if x > root.data:
            root.right = self.delNode(root.right, x)
        elif x < root.data:
            root.left = self.delNode(root.left, x)
        else:
            # case we are at the node to delete 
            
            # Case 1 no left subtree
            if not root.left:
                return root.right
            
            # Case 2 no right subtree
            if not root.right:
                return root.left
                
            # Case 3 : both present
            # find the first successor in the right subtree
            successor = root.right
            while successor.left:
                successor = successor.left
            
            # found the successor 
            # swap the values with root
            root.data = successor.data # copy the value in the current node
            root.right = self.delNode(root.right, successor.data) #delete the successor node
        
        
        return root