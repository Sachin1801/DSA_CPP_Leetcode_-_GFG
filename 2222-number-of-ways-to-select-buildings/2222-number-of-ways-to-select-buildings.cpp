class Solution {
public:
    long long numberOfWays(string s) {
        int n = s.size();
        long long prefzero=0,suffzero =0,suffone=0,prefone=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='0')
              suffzero++;
            else 
              suffone++;
        }
        long long ans =0;
        for(int i =0;i<s.size();i++){
            if(s[i]=='1'){
              ans= ans + prefzero*suffzero;
                suffone--;
                prefone++;
            }else{
                ans = ans + suffone*prefone;
                prefzero++;
                suffzero--;
            }
        }
        return ans;
    }
};