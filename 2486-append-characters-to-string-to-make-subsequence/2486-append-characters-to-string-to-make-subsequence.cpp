class Solution {
public:
    int appendCharacters(string s, string t) {
        int i=0,j=0;
        int ss= s.size();
        int ts = t.size();

        while(i<ss && j<ts){
            if(s[i]==t[j]) i++,j++;
            else i++;
        }
        if(j==ts) return 0;
        else return ts-j;
    }
};