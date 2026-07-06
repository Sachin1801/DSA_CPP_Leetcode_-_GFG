class Solution:
    def removeCoveredIntervals(self, intervals: List[List[int]]) -> int:
        intervals.sort(key=lambda x: (x[0], -x[1]))
        print(intervals)
        ans = 0
        max_end = -1

        for start, end in intervals:
            if end > max_end:
                max_end = end
                ans = ans+1
        
        return ans