class Solution {
  public:
    // Function to check if b is a subset of a
    bool isSubset(vector<int> &a, vector<int> &b) {
        // Your code here
        unordered_map<int,int> m;
        for(int i: a){
            m[i]++;
        }
        for(int i:b){
            if(m.find(i)==m.end()) return false;
            else{
              m[i]--;
              if(m[i]==0) m.erase(i);
            } 
        }
        return true;
    }
};