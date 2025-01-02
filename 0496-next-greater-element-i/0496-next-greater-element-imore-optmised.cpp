class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> m;
        vector<int> ans;
        stack<int> s;
        for(int i=nums2.size()-1;i>=0;i--){
            while(!s.empty() and s.top()<= nums2[i]){
                s.pop();
            }
            if(!s.empty()){
                m[nums2[i]]=s.top();
            }else{
                m[nums2[i]]=-1;
            }
            s.push(nums2[i]);
        }
        for(int x: nums1){
            ans.push_back(m[x]);
        }
        return ans;
        
    }
};