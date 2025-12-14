// Last updated: 12/14/2025, 4:17:07 PM
class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        // if(s1.length()==1){
        //     if(s1[0]==s2[0])
        //         return true;
        // }
        pair<char,char> p;
        int cnt = 0;
        for(int i=0;i<s1.length();i++){
            if(s1[i]!=s2[i]){
                if(cnt>2)
                    return false;
                else if(cnt>0){
                    if(s1[i]!=p.second or s2[i]!=p.first)
                        return false;
                    cnt++;
                }else{
                    p.first = s1[i];
                    p.second= s2[i];
                    cnt++;
                }
            }
        }
        if(cnt==1) return false;
        return true;
    }
};