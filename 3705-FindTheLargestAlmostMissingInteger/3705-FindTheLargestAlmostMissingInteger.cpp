// Last updated: 12/14/2025, 4:15:21 PM
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        static const int OFFSET = 50;
        vector<int> pos[101];
        int n = (int)nums.size(), ans = -1;

        for(int i = 0; i < n; i++){
            pos[nums[i] + OFFSET].push_back(i);
        }

        for(int x = -50; x <= 50; x++){
            auto &p = pos[x + OFFSET];
            if(p.empty()) continue;
            vector<pair<int,int>> intervals;
            for(int idx: p){
                int L = idx - (k - 1);
                int R = idx;
                L = max(L, 0);
                R = min(R, n - k);
                if(L <= R){
                    intervals.push_back({L, R});
                }
            }
            if(intervals.empty()) continue;
            sort(intervals.begin(), intervals.end());
            int mergedLen = 0, st = intervals[0].first, en = intervals[0].second;
            for(int i = 1; i < (int)intervals.size(); i++){
                int s = intervals[i].first, e = intervals[i].second;
                if(s <= en + 1){
                    en = max(en, e);
                } else {
                    mergedLen += (en - st + 1);
                    st = s; 
                    en = e;
                }
            }
            mergedLen += (en - st + 1);
            if(mergedLen == 1) ans = max(ans, x);
        }

        return ans;
    }
};
