class Solution {

    private:
        int helper(string s, int left, int right, int n){
            if(left > right){
                return 0;
            }
            while(left >=0 && right < n && s[left]==s[right]){
                left--;
                right++;
            }
            return right - left - 1;
        }
    

public:
    string longestPalindrome(string s) {
        if(s=="" || s.length()<1) return "";
        int left = 0;
        int right = 0;
        int n = s.length();
        for(int i=0;i<n;i++){
            int len1 = helper(s,i,i,n);
            int len2 = helper(s,i,i+1,n);
            int len = max(len1,len2);
            if(len > right - left){
                left = i - ((len-1)/2);
                right = i + (len/2);
                }
        }
        return s.substr(left,right-left+1);
    }
};