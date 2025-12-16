
const int mod  = 1e9+7 ;
class Solution {
  public:
    int distinctSubseq(string &str) {
        // code here
        int n = str.length();
        if(n==1) return 2;
        
        vector<int> dp(n+1,0);
        int curr, prev;
        dp[0]=1;
        
        // curr= 1;
        prev = 1;
        unordered_map<char,int> idx;
        for(int i=1;i<=n;i++){
            char ch = str[i-1];
            curr = (prev%mod * 2)%mod;
            //check if we have a previous occurence
            if(idx.find(ch) == idx.end()){
                //first occurence of the character
                dp[i] = (curr)%mod;
                // idx[ch] = i-1;
            }else{
                //if the character is a duplicate and is repeating
                int lastOcc = idx[ch];
                dp[i] = (curr - dp[lastOcc] + mod )%mod;
                // idx[ch] = i-1;
            }
            idx[ch] = i-1; 
            prev = (dp[i])%mod;
        }
        return (dp[n]%mod);
    }
};