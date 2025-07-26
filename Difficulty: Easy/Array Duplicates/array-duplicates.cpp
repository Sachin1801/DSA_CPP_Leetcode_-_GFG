class Solution {
  public:
    vector<int> findDuplicates(vector<int>& arr) {
        // code here
        unordered_set<int> st;
        vector<int> ans;
        
        for(int i=0;i<arr.size();i++){
            if(st.find(arr[i])!=st.end()) ans.push_back(arr[i]);
            else st.insert(arr[i]);
        }
        return ans;
    }
};