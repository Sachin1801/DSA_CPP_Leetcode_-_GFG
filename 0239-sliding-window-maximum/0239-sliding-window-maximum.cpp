class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            if(!q.empty() && q.front() <= i-k){
                q.pop_front();
            }
            while(!q.empty() and nums[q.back()] <= nums[i]){
                q.pop_back();
            }
            q.push_back(i);
            if(i>=k-1){
                ans.push_back(nums[q.front()]);
            }
        }
        return ans;
        
    }
};