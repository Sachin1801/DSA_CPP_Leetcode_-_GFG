class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
        int ans = 0,n = colors.size();
        for(int i=0;i<n;i++){
            if(colors[(i+1)%n]!=colors[i%n] && colors[(i+1)%n]!=colors[(i+2)%n]) ans++;
        }
        return ans;
    }
};