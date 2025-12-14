// Last updated: 12/14/2025, 4:16:43 PM
class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        // long long ans = 0;
        long long n = (long long)nums.size();
        unordered_map<long long,long long> m; 
        long long size = (n*(n-1))/2;
        long long goodpairs = 0;
        for(int i=0;i<n;i++){
            if(m.find(i-nums[i])!=m.end()) goodpairs+=m[i-nums[i]];
            m[i-nums[i]]++;
        }
        return size-goodpairs;
    }
};