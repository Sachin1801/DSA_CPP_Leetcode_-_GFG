class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(int i: nums){
            pq.push(i);
        }
        int ans = INT_MIN;
        if(k==1){
            return pq.top();
        }
        while(k--){
            if(k==0){
                ans = pq.top();
            }
            pq.pop();
        }
        return ans;
    }
};