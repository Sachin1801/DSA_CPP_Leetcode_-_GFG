'''
class Node:
    def __init__(self, val, k):
        self.right = None
        self.data = val
        self.left = None
'''
class Solution:
    # returns the inorder successor of the Node x in BST (rooted at 'root')
    def inorderSuccessor(self, root, x):
        # Code here
        if not root:
            return -1
            
        
        
        def getInorder(root):
            curr =root
            inorder = []
            while curr:
                
                # Case 1 : if we have no left
                    # 1) we push to inorder
                    # 2) move to curr.right
                if not curr.left:
                    inorder.append(curr.data)
                    curr = curr.right
                else: # case 2 : if we have a left
                    # Case 1 : no thread to the rightmost node in the left subtree
                    prev = curr.left
                    while prev.right and prev.right != curr :
                        prev = prev.right
                    
                    if not prev.right:
                        prev.right = curr
                        curr = curr.left
                    else:
                        prev.right = None
                        inorder.append(curr.data)
                        curr = curr.right
                        
            return inorder
        
        curr = root
        inorder = getInorder(curr)
        
        i = inorder.index(x.data)
        if i == len(inorder) - 1:
            return -1
        return inorder[i+1]
        
        