class Solution {
  public:

    // Function to return length of longest subsequence of consecutive integers.
    int longestConsecutive(vector<int>& arr) {
        // Your code here
        vector<int> temp(100001,0);
        for(int i=0;i<arr.size();i++){
            temp[arr[i]]++;
        }
        
        int max_ans=INT_MIN,curr_ans=0;
        if(temp[0]>=1)curr_ans = 1,max_ans = 1;
        for(int i=1;i<temp.size();i++ ){
            if(temp[i]>=1 && temp[i-1]>=1) {
                curr_ans++;
            }
            else if(temp[i]>=1 && temp[i-1]==0){
                curr_ans = 1;
                max_ans= max(max_ans, curr_ans);
            }
            else{
                max_ans = max(max_ans,curr_ans);
                curr_ans= 0;
            }
        }
        return max_ans;
    }
};