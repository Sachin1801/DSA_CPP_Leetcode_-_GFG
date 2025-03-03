class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int ans = 0;
        if(s.size()==0) return 0;
        if(g.size()==0) return 0;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int gs = g.size();
        int ss = s.size();
        if(g[0]> s[ss-1]) return 0;
        int i = gs-1,j =ss-1;
        while(i>=0 && j >=0){
            if(s[j] >= g[i]){
                ans++;
                i--;
                j--;
            }
            else
                i--;
        }
        return ans;
    }
};