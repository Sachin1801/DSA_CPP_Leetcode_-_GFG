class Solution {
public:
    int numberOfSubstrings(string s) {
        int ans =0;
        int i=0,j=0;
        vector<int> v(3,-1);
        while(j<s.length()){
            v[s[j]-'a']=j;
            if(v[0]>-1 and v[1]>-1 and v[2]>-1){
                int min_idx = min(v[0],min(v[1],v[2]));
                    ans += min_idx+1;
            }
            j++;
        }
        return ans;
    }
};