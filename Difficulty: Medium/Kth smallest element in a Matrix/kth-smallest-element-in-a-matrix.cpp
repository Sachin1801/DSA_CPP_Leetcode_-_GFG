class Solution {
  public:
    int kthSmallest(vector<vector<int>> &mat, int k) {
        // code here
        priority_queue<int,vector<int>,greater<int>> minHeap;
        
        int n = mat.size();
        int m = mat[0].size();
        for(int i=0; i<n; i++){
            for(int j=0; j<m ; j++){
                minHeap.push(mat[i][j]);
            }
        }
        while(k>1){
            minHeap.pop();
            k--;
        }
        return minHeap.top();
    }
};
