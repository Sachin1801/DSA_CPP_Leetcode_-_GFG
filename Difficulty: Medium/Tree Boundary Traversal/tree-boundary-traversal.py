'''
class Node:
    def __init__(self, val):
        self.data = val
        self.right = None
        self.left = None
'''

class Solution:
    def boundaryTraversal(self, root):
        # code here
        if root is None:
            return []
            
        if root.left is None and root.right is None:
            return [root.data]
        
        ans = []
        if root.left or root.right:
            ans.append(root.data)
            
        # take out the left boundry first of all leaiving the leaf nodes
        node = root.left
        
        while node:
            if node.left or node.right:
                ans.append(node.data)
            
            # try to go to the left by default, if no left go to right
            if node.left:
                node = node.left
            elif node.right:
                node = node.right
            else:
                break
        
        # get all the leaf nodes 
        node = root
        in_order =[]
        
        def Inorder(root):
            if root is None:
                return
            
            # leaf node : add to inorder
            if root.left is None and root.right is None:
                in_order.append(root.data)
                return
            
            # go to the left first
            Inorder(root.left)
            
            # we don't want the root
            
            # then go to the right node
            Inorder(root.right)
        
        Inorder(node)
                
        ans.extend(in_order)
        
        # now get the right boundry in reverse
        st = []
        node = root.right
        
        if node is None:
            return ans
            
        
        while node:
            if node.left or node.right:
                st.append(node.data)
            
            # check for the right node first
            if node.right:
                node = node.right
            # if right not present go for the left node
            elif node.left:
                node = node.left
            else:
                break
            
        
        # push the values in the stack in LIFO order 
        while len(st) > 0:
            top = st.pop()
            ans.append(top)
        
        
        return ans
        
        
        
        
        
        
        
        
        
        
        
        
        
        
            
        