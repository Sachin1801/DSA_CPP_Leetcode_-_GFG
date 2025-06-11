class Solution {
private:
    int getState(int count_a, int count_b){
        int parity_a = count_a % 2;
        int parity_b = count_b % 2;

        if(parity_a == 1 && parity_b==1) return 3;
        else if(parity_a == 1 && parity_b==0) return 2;
        else if(parity_a == 0 && parity_b==1) return 1;
        return 0;
    }

public:
    int maxDifference(string s, int k) {
        int n= s.length();

        int result = INT_MIN;

        for(char a = '0'; a <= '4'; a++){
            for(char b = '0'; b <= '4'; b++){
                
                int count_a = 0;
                int count_b = 0;

                //varibales to store the prev count till l for a and b
                int prev_a = 0;
                int prev_b = 0;

                //array to store the minimum value of all possible left combinations
                vector<int> smallestPossibleDiff(4,INT_MAX);

                //left and right pointers for the sliding window

                //start the sliding window
                int l = -1;
                int r =0;

                while(r < n){

                    count_a += (s[r]==a) ? 1 : 0;
                    count_b += (s[r] == b) ? 1 : 0;

                    //we try to shrink from the left
                    while(r-l >=k && count_b - prev_b >=2 && count_a - prev_a >=1){
                        
                        int leftState = getState(prev_a, prev_b);
                        smallestPossibleDiff[leftState] = min(smallestPossibleDiff[leftState], prev_a - prev_b);

                        l++;
                        prev_a += (s[l]==a) ? 1:0;
                        prev_b += (s[l]==b) ? 1: 0;
                    }

                    int rightState = getState(count_a, count_b);
                    int remStateNeeded = rightState ^ 2;
                    int bestMinDiff = smallestPossibleDiff[remStateNeeded];

                    if(bestMinDiff != INT_MAX){
                        result = max(result, (count_a - count_b) - bestMinDiff);
                    }

                    //as it is a sliding window
                    r++;
                }
            }
        }
        return result;
    }
};