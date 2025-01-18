class Solution {
public:
    int maxScore(string s) {
        int arr[2]={0};
        for(int i=0;i<s.length();i++){
            arr[s[i]-'0']++;
        }
        int zeros=0;
        int ans = 0;
        for(int i=0;i<s.length()-1;i++){
            if(s[i]=='0'){
                zeros++;
                ans = max(ans,zeros+arr[1]);
            }else{
                arr[1]--;
                ans = max(ans,zeros+arr[1]);
            }
        }
        return ans;
    }
};