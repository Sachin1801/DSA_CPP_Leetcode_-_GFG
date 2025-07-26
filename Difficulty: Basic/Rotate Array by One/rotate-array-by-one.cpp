// User function Template for C++

class Solution {
  public:
    void rotate(vector<int> &arr) {
        // code here
        vector<int> temp;
        int n = arr.size();
        for(int i = arr.size()-1; i< (2*arr.size())-1 ;i++){
            temp.push_back(arr[i%n]);
        }
        arr = temp;
    }
};