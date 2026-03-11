class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        d = dict()

        for i, val in enumerate(nums):
            rem = target - val

            if rem in d:
                return [i,d[rem]]
            
            d[val] = i

        return []

        