class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> m;
        unordered_map<char,char> temps;
        for(int i=0;i<s.length();i++){
            char tempchar1 = s[i];
            char tempchar2 = t[i];

            if(m.find(tempchar1)==m.end()){
                if(temps.find(tempchar2)!=temps.end()){
                    return false;
                }
                temps[t[i]]=s[i];
                m[s[i]]=t[i];
            }else if(m[tempchar1]!=tempchar2){
                return false;
            }
        }
        return true;
    }
};