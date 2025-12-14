// Last updated: 12/14/2025, 4:15:34 PM
class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int maxlen = 1, ans =0 , n=colors.size();

        for(int i=1;i<=n-1+k-1;i++){
            if(colors[i%n]!= colors[(i-1+n)%n]){
                maxlen++;
            }else{
                maxlen = 1;
            }

            if(maxlen >=k) ans++;
        }
        return ans;
    }
};