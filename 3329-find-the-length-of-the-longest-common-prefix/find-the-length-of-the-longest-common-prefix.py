class Solution:
    def longestCommonPrefix(self, arr1: List[int], arr2: List[int]) -> int:
        hash_set = set()
        for n in arr2:
            while n > 0:
                hash_set.add(n)
                n = n // 10
                

        # for each number in arr1, check from it's last element if the prefix is present or not
        ans = 0
        for n in arr1:
            # print(n)
            while n > 0:
                if n in hash_set:
                    ans = max(ans, len(str(n)))
                    # print(f"Ans updated with value {n} and the new ans is : {ans}")
                    break
                else:
                    n = n // 10 
                    # print(f" the value of n: {n}")

        return ans

        # print(hash_set)