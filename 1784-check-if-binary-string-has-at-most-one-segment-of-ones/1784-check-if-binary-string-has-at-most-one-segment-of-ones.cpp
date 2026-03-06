class Solution {
public:
    bool checkOnesSegment(string s) {
        int n = s.length();
        if(n==1){
            return s[0] == '1' ? true : false;
        }
        bool atMostOne = false;
        for(int i=0;i<n;i++){
            if(s[i] == '1'){
                if(atMostOne == true) return false;
                while(i< n-1 && s[i] == '1'){
                    i++;
                }
                atMostOne = true;
            }
            
        }
        return atMostOne;
    }
};