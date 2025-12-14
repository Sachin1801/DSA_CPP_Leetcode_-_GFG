// Last updated: 12/14/2025, 4:17:05 PM
class Solution {
public:
    string largestOddNumber(string num) {
        string ans="";
        for(int i=num.length()-1;i>=0;i--){
            if(num[i]%2!=0){
                return num.substr(0,i+1);
            }
        }
        return ans;
    }
};