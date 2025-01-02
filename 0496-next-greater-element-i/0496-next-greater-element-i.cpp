class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nge(nums2.size(),-1);
        vector<int> ans;
        stack<int> s;
        for(int i=nums2.size()-1;i>=0;i--){
            while(!s.empty() and s.top()<= nums2[i]){
                s.pop();
            }
            if(!s.empty()){
                nge[i]=s.top();
            }
            s.push(nums2[i]);
        }
        for(int x: nums1){
            int i;
            for(i=0;i<nums2.size();i++){
                if(nums2[i]==x){
                    ans.push_back(nge[i]);
                    break;
                }
            }
        }
        return ans;
        
    }
};