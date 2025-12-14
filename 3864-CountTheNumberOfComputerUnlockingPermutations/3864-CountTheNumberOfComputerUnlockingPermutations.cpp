// Last updated: 12/14/2025, 4:15:13 PM


class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        int MOD = 1e9+7;
        int min_global = complexity[0];

        //quick check if possible for not
        for(int i=1;i<complexity.size();i++){
            if(complexity[i] <= min_global) return 0;
        }

        //if the above check passes then we can directly compute the number of permutations
        int n = complexity.size()-1;
        unsigned long long  ans = 1;
        while(n>=1){
            ans *= n;
            ans %= MOD;
            n--;
        }
        return (int)ans;
    }
};