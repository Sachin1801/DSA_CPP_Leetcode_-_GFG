class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int n = intervals.size();

        int newstart = newInterval[0];
        int newend = newInterval[1];

        int i=0;
        while(i<n && intervals[i][1] < newstart){
            ans.push_back(intervals[i++]);
        }

        while(i<n && intervals[i][0] <= newend ){
            newstart = min(newstart,intervals[i][0]);
            newend = max(newend,intervals[i][1]);
            i++;
        }
        ans.push_back({newstart,newend});
        while(i<n){
            ans.push_back(intervals[i++]);
        }
        return ans;
    }
};