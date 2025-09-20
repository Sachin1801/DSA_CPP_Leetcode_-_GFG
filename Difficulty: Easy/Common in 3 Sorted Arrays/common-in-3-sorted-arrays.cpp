class Solution {
  public:
    // Function to find common elements in three arrays.
    vector<int> commonElements(vector<int> &arr1, vector<int> &arr2,
                               vector<int> &arr3) {
        // Code Here
        set<int> unique(arr1.begin(),arr1.end());
        vector<int> ans;
        for(int x: arr2){
            if(unique.find(x)==unique.end()) continue;
            else ans.push_back(x);
        }
        unique.clear();
        unique.insert(ans.begin(),ans.end());
        ans.clear();
        set<int> result;
        for(int x: arr3){
            if(unique.find(x)==unique.end()) continue;
            else result.insert(x);
        }
        for(int x: result){
            ans.push_back(x);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};