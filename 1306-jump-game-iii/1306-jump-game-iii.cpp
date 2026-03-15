class Solution {
private:
    bool solve(vector<int> &arr, vector<bool> &visited, int i){
        if(i >=arr.size() || i < 0) return false;
        if(visited[i] == true) return false;
        
        // target case
        if(arr[i] == 0){
            // possible[i] = 1;
            return true;
        }

        visited[i] = true;
        // two ways: 
            // to go positive side
            // to go negative side
        
        int rightIdx = arr[i] + i;
        int leftIdx = i - arr[i];
        
        bool rightPossible = solve(arr, visited, rightIdx);
        if(rightPossible) return true;
        bool leftPossible = solve(arr, visited, leftIdx);
        if(leftPossible || rightPossible) return true;
        return false;
    }


public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<bool> visited(n, false);

        // visited[start] = true;
        return solve(arr, visited, possible, start);

    }
};