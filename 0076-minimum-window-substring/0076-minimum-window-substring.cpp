class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> m;
        for(int i=0;i<t.length();i++){
            m[t[i]]++;
        }
        int left = 0, right =0;
        int cnt = 0;
        int start_idx = -1;
        int minlen = INT_MAX;
        while(right<s.size()){
            if(m[s[right]]>0)
                cnt++;
            m[s[right]]--;
            while(cnt==t.size()){
                if(right-left+1 < minlen){
                    minlen = right-left+1;
                    start_idx = left;
                }
                m[s[left]]++;
                if(m[s[left]]>0)
                    cnt--;
                left++;
            }
            right++;
        }
        return start_idx == -1 ? "": s.substr(start_idx,minlen);
    }
};