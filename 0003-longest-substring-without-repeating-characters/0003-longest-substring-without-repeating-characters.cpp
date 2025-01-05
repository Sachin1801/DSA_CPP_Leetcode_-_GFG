class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length()==0)
            return 0;
        int j=0;
        int i=0;
        int ans = 1;
        unordered_map<char,int> m;
        while(j<s.length()){
            if(m.find(s[j])!=m.end()){ //or use m.find()
                ans = max(ans,j-i);
                while(i<(m[s[j]]+1)){
                    m.erase(s[i]);
                    i++;
                }
                m[s[j]]= j;
            }else{
                m[s[j]]=j;
            }
            j++;
        }
        int sz = m.size();
        return max(sz,ans);
    }
};