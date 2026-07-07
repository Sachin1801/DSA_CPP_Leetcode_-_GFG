class Solution:
    def sumAndMultiply(self, n: int) -> int:
        
        # option 1 : int to str
        #     check for non-zero -> O(n)
        #         sum = convert and add to sum -> O(1)
        #         form new number
        if n == 0:
            return 0
        numStr = str(n)
        newNum = ""
        totSum = 0
        for ch in numStr:
            if ch is not '0':
                totSum = totSum + int(ch)
                newNum = newNum + ch

        return totSum * int(newNum)
            
            
            
        