class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> nge(nums.size(),-1);
        int n = nums.size();
        stack<int> s;
        for(int i = (2*n)-1; i>=0;i--){
            while(!s.empty() and s.top() <= nums[i%n]){
                s.pop();
            }
            if(i<n and !s.empty()){
                nge[i]=s.top();
            }
            s.push(nums[i%n]);
        }
        return nge;
    }
};