// Last updated: 12/14/2025, 4:15:38 PM
class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int,int> ball_color;
        unordered_map<int,int> freq;
        int n = queries.size();
        vector<int> ans(n,0);
        for(int i=0;i<n;i++){
            int color = queries[i][1];
            int label = queries[i][0];
            
            //remove a color if tge chosen ball was already pointed
            if(ball_color.count(label)){
                freq[ball_color[label]]--;
                if(freq[ball_color[label]]==0){
                    freq.erase(ball_color[label]);
                }
                //paint the ball with given color
                
            }
            ball_color[label]=color;
                freq[color]++;
                ans[i]=freq.size();
        }
        return ans;
    }
};