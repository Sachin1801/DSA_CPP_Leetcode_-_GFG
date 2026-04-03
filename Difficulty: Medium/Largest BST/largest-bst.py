class Solution:
    def largestBst(self, root):
        # Your code here
        if not root:
            return 0
        largest_size = 0
        
        def postorder(root):
            nonlocal largest_size
            if not root:
                return (0, float('-inf'), float('inf'))
            
            if not root.left and not root.right:
                return (1,root.data,root.data) # returning (size, max_val, min_val)
                
            
                
            left_tuple = postorder(root.left)
            left_size = left_tuple[0]
            left_max = left_tuple[1]
            left_min = left_tuple[2]
            
            
            right_tuple = postorder(root.right)
            right_size= right_tuple[0]
            right_max = right_tuple[1]
            right_min = right_tuple[2]
            
            if root.data > left_max and root.data < right_min:
                tot_size = 1 + left_size + right_size
                # right_max = root.data if right_max = int('-inf') else right_max
                # left_min = root.data if left_min == int('inf') else left_min
                return (tot_size, max(right_max, root.data), min(left_min, root.data))
            else:
                largest_size = max(left_size, right_size)
                return (largest_size, float('inf'), float('-inf'))
        
        final = postorder(root)
        return final[0]