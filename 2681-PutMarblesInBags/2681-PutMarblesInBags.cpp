// Last updated: 12/14/2025, 4:15:59 PM
class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        if(weights.size()==1 || k==1) return 0;
        priority_queue<long long,vector<long long>> maxheap;
        priority_queue<long long,vector<long long>,greater<long long>> minheap;

        int n = weights.size();
        for(int i=0;i<n-1;i++){
            maxheap.push(weights[i]+weights[i+1]);
            minheap.push(weights[i]+weights[i+1]);
        }

        long long max_score = weights[0]+ weights.back();
        long long min_score = weights[0]+ weights.back();
        while(k>1){
            max_score += maxheap.top();
            maxheap.pop();
            min_score += minheap.top();
            minheap.pop();
            k--;
        }
        return max_score - min_score;
    }
};