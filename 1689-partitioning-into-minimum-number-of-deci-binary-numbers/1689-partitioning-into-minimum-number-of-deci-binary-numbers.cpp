class Solution {
public:
    int minPartitions(string n) {
        int ans = 0;
        for(int i = 0; i< n.length();++i){
            char ch = n[i];
            // convert char to int 
            int currNum = ch - '0';
            if(currNum > ans) ans = currNum;

        }
        return ans;
    }
};