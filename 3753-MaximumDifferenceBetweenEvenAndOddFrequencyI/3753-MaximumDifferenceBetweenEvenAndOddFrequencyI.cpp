// Last updated: 12/14/2025, 4:15:18 PM
class Solution {
public:
    int maxDifference(string s) {
        vector<int> freq(26,0);

        for(int i=0;i<s.length();i++){
            freq[ s[i] -'a']++;
        }

        int max_freq = 0, min_freq=INT_MAX;


        for(auto& f: freq){
            if(f==0) continue;
            if(f&1){
                max_freq = max(max_freq,f);
            }else{
                min_freq = min(min_freq,f);
            }
        }
        return max_freq-min_freq;
    }
};