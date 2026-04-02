#User function Template for python3

class Solution:
    def isBSTTraversal(self, arr):
        # Code here
        n = len(arr)
        if n == 0:
            return True
        
        for i in range(n-1):
            if arr[i] >= arr[i+1]:
                return False
        
        return True
        