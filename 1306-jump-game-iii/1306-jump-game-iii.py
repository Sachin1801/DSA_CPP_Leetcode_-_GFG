class Solution:     
    def canReach(self, arr: List[int], start: int) -> bool:
        visited = [False] * len(arr)

        def solve(idx: int ) -> bool:
            if idx  >= len(arr) or idx < 0:
                return False
            if visited[idx] == True:
                return False
            
            if arr[idx] == 0:
                return True
            
            visited[idx] = True

            right_idx = idx + arr[idx]
            left_idx = idx - arr[idx]

            rightPossible = solve(right_idx)
            leftPossible = solve(left_idx)

            if rightPossible == True or leftPossible == True:
                return True
            return False

        return solve(start)
        