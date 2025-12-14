// Last updated: 12/14/2025, 4:15:42 PM
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long,vector<long long>, greater<long long>> pq;
        for(int i=0;i<nums.size();i++){
            pq.push((long long)nums[i]);
        }
        long long ans = 0;
        while(pq.top() < k){
            long long t1 = pq.top();
            pq.pop();
            long long t2 = pq.top();
            pq.pop();
            pq.push(((long long)(t1*2)+t2));
            ans++;
        }
        return ans;
    }
};