// Last updated: 12/14/2025, 4:17:09 PM
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans ="";
        int n1 = word1.length();
        int n2 =word2.length();
        int w1=0, w2=0;
        while(w1< n1 and w2 < n2){
            ans = ans + word1[w1++] ;
            ans = ans + word2[w2++];
        }
        while(w1 < n1){
            ans += word1[w1++];
        }
        while(w2 < n2){
            ans += word2[w2++];
        }
        return ans;
    }
};