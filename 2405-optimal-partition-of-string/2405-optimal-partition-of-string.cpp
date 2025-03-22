class Solution {
public:
    int partitionString(string s) {
        int ans = 0;
        unordered_set<char> taken;
        string curr="";
        int n = s.length();
        for(int i=0;i<=n;i++){
            if(taken.find(s[i])!=taken.end()){
                ans++;
                curr="";
                taken.clear();
            }
            curr += s[i];
            taken.insert(s[i]);    
        }
        if(curr!="") ans++;
        return ans;
    }
};