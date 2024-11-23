class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(),intervals.end());
        vector<vector<int> >ans;
        int row=0;
        for(int i=0;i<n;++i){
            int start = intervals[i][0];
            int end = intervals[i][1];
            if(ans.empty() || start > ans.back()[1]){
                ans.push_back(intervals[i]);
            }
            else{
                ans.back()[1] = max(ans.back()[1],end);
            }
        }
        return ans;
    }
};