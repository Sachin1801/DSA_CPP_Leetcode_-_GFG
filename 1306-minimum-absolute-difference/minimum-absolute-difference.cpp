class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int n = arr.size();
        //getting the first abs diff to start with
        // pair<int,int> temp = {arr[0],arr[1]}
        int minAbs = INT_MAX;

        vector<vector<int>> ans;
        for(int i=0;i<n-1;i++){
            if(abs(arr[i+1] - arr[i]) < minAbs )
                minAbs = abs(arr[i+1]-arr[i]); 
        }   

        // now push all the pairs with absDif == minAbs

        for(int i=0;i<n-1;i++){
            if(abs(arr[i+1]-arr[i]) == minAbs){
                vector<int> temp = {arr[i],arr[i+1]};
                ans.push_back(temp);
            }
        }

        return ans;
    }
};