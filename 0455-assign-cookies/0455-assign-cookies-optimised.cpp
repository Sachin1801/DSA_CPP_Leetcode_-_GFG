class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        if(s.size()==0)
            return 0;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int ans = 0;
        int i=0,j=0;
        while(i< g.size() && j<s.size()){
            if(g[i]<=s[j]){
                i++;
                j++;
                ans++;
            }else{
                j++;
            }
        }
        return ans;
    }
};