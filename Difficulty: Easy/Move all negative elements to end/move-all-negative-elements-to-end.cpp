class Solution {
  public:
    void segregateElements(vector<int>& arr) {
        // Your code goes here
        vector<int> temp;
        vector<int> neg;
        for(int i=0;i< arr.size();i++){
            if(arr[i] >=0){
                temp.push_back(arr[i]);
            }else{
                neg.push_back(arr[i]);
            }
        }
        copy(temp.begin(),temp.end(),arr.begin());
        copy(neg.begin(),neg.end(),arr.begin() + temp.size());
    }
};