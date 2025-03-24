class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        auto cmp = [](vector<int> &A, vector<int> &B){
            return A[1]<B[1];
        };

        sort(points.begin(),points.end(),cmp);
        int arrow_shot = points[0][1];
        int cnt =1;
        for(int i=1;i<points.size();i++){
            if(arrow_shot >= points[i][0]) continue;
            cnt++;
            arrow_shot = points[i][1];
        }
        return cnt;
    }
};