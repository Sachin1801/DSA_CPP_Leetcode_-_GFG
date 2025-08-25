class Solution {
  public:
    // Function to partition the array around the range such
    // that array is divided into three parts.
    void threeWayPartition(vector<int>& arr, int a, int b) {
        // code here
        stack<int> less;
        stack<int> in_range;
        stack<int> more;
        
        int n = arr.size();
        
        for(int i =0;i<n;i++){
            if(arr[i] < a) less.push(arr[i]);
            else if(arr[i] >=a && arr[i] <=b) in_range.push(arr[i]);
            else more.push(arr[i]);
        }
        
        
        vector<int> ans ;
        while(!less.empty()){
            ans.push_back(less.top());
            less.pop();
        }
        while(!in_range.empty()){
            ans.push_back(in_range.top());
            in_range.pop();
        }
        while(!more.empty()){
            ans.push_back(more.top());
            more.pop();
        }
        arr=ans;
    }
};