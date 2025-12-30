class Solution:
    def pyramidTransition(self, bottom: str, allowed: List[str]) -> bool:

        if len(allowed) ==0 : return False

        # build the allowed map 
        allow ={}
        for rule in allowed:
            pair = rule[:2] #to get the first two letters -> s.substr(0,n)
            top_char = rule[2]

            if pair not in allow:
                allow[pair] = [] #this is to make the particular allow[key] a list
            allow[pair].append(top_char)

        
        #step 2: intiliase memoization and start the recursion
        memo = set()
        return self._solve(bottom,"",allow,memo)

    def _solve(self, bottom: str, currBottom: str, allow: dict, memo: set):

        if(len(bottom) ==1) : return True

        if(len(currBottom) == len(bottom)-1):
            return self._solve(currBottom,"", allow,memo)

        # memoization 
        state = (bottom,currBottom)
        if state in memo:
            return False

        j = len(currBottom)
        pair = bottom[j:j+2] #slicing -> start : end

        # if this pair has no valid top_char, then fail
        if pair not in allow:
            memo.add(state)
            return False

        # check for all possible top_char for this pair 
        for next_top in allow[pair]:
            currBottom += next_top #string concatination

            #early pruning to check if the we have a top for the pair formed 
            if len(currBottom) > 1:
                last = currBottom[-2:]
                if last not in allow:
                    currBottom = currBottom[:-1]
                    continue

            if self._solve(bottom,currBottom, allow, memo):
                return True
            #remove the last char
            currBottom = currBottom[:-1]


        #mark this state as explored and failed
        memo.add(state)
        return False 


        