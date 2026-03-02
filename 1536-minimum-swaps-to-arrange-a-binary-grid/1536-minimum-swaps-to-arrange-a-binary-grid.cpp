class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int ans = 0;
        int n = grid.size();
        int zerosRequired  = n -1;

        //store the ending consecutive zeros of each row and store it in a map with its row location 
        vector<int> tz(n);

        for(int i = 0; i < n; i++){
            int consecZeros=0;
            for(int j = n-1; j>=0; j--){
                if(grid[i][j] == 0) consecZeros++;
                else break;
            }
            tz[i] = consecZeros;
        }

        // sort the map based on increasing row numbers to get the latest and the top row for less swaps
        // for(auto& p: m ){
        //     sort(p.second.begin(), p.second.end());
        // }

        for(int i=0; i < n-1;i++){
            int found = -1;
            
            int req = n - 1 - i;
            for(int j = i; j< n; ++j){
                if(tz[j] >= req){
                    found = j;
                    break;
                }
            }
            if(found == -1) return -1;
            ans += found - i;

            //swap the rows of trailing zeros
            for(int j = found ; j > i ; j--){
                swap(tz[j], tz[j-1]);
            }
        }
        return ans;
    }
};