class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> m(26);
        int maxlen =0;
        int maxfreq=0;

        int i=0,j=0;
        while(j<s.length()){
            m[s[j]]++;
            maxfreq = max(maxfreq,m[s[j]]);
            int windowsize = j-i+1;
            int conversion = windowsize - maxfreq;
            if(conversion >k){
                m[s[i]]--;
                i++;
            }
            if(conversion <=k){
                maxlen = max(maxlen, windowsize);
            }
            j++;
        }
        return maxlen;
    }
};