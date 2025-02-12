class Solution {
private:
    int computeDigitSum(int n){
        int sum =0;
        while(n > 0){
            sum += n%10;
            n /= 10;
        }
        return sum;
    }

public:
    int maximumSum(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,priority_queue<int>> m;
        for(int i=0;i<n;i++){
            int digsum = computeDigitSum(nums[i]);
            m[digsum].push(nums[i]);
        }
        int maxsum = -1;
        for(auto p: m){
            auto pq = m[p.first];
            if(pq.size()==1)
                continue;
            int csum =0;
            csum += pq.top();
            pq.pop();
            if(pq.size()>=1){
                csum+= pq.top();
                pq.pop();
                if(maxsum < csum ){
                    maxsum = max(maxsum,csum);
                }
            }
        }
        return maxsum;
    }
};