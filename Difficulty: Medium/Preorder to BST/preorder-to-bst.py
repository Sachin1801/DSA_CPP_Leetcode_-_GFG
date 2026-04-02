#User function Template for python3

class Node:

    def __init__(self, data=0):
        self.data = data
        self.left = None
        self.right = None


def FormTree(root, pre, size, i, ub):
    if i[0] >= size:
        return root
    
    if pre[i[0]] > ub:
        # root.left = None
        # root.right = None
        return root
    
    # Step 1 : check if the curr val : pre[i] > root.data or < root.data
    if pre[i[0]] < ub and root.data > pre[i[0]]:
        root.left = Node(pre[i[0]])
        i[0]+=1
        FormTree(root.left, pre,size,i,root.data)
    
    if i[0] < size and pre[i[0]] < ub and root.data < pre[i[0]]:
        root.right = Node(pre[i[0]])
        i[0]+=1
        FormTree(root.right, pre, size, i, ub)
        
    return root  

#Function that constructs BST from its preorder traversal.
def Bst(pre, size) -> Node:
    #code here
    
    #edge case : if the preorder list is empty
    if size ==0:
        return None
    
    # Step 1 : form the root node
    # form the upper bound limit
    ub = float('inf')
    root = Node(pre[0])
    
    i = [1]
    FormTree(root, pre, size,i, ub)
    return root