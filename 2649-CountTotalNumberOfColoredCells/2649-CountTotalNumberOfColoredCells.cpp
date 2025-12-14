// Last updated: 12/14/2025, 4:16:00 PM
class Solution {
public:
    long long coloredCells(int n) {
        long long ans=1;
        if(n==1) return ans;
        for(int i=1;i<n;i++){
            ans += (4*i); 
        }
        return ans;
    }
};