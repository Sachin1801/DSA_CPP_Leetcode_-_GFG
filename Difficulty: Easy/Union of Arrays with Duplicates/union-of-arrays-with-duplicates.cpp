class Solution {
  public:
    vector<int> findUnion(vector<int>& a, vector<int>& b) {
        // code here
        unordered_set<int> st;
        for(int x: a){
            st.insert(x);
        }
        for(int x:b){
            st.insert(x);
        }
        vector<int> ans(st.begin(),st.end());
        return ans;
    }
};