class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows ==1){
            return s;
        }
        vector<string> v(numRows);
        int n = s.size();
        int i = 0;     
        while(i < n){
            for(int row=0; row < numRows && i< n; row++){
                v[row] += s[i++];
            }
            for(int row = numRows - 2; row>0 && i < n;row--){
                v[row] += s[i++];
            }
        }

        string ans="";
        for(auto &row: v){
            ans += row;
        }

        return ans;
    }
};