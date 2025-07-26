class Solution {
  public:
    void mergeArrays(vector<int>& a, vector<int>& b) {
        // code here
        int n = a.size(), m = b.size();
        int i =0,j=0,k=n-1;
        
        while(k>=i){
            if(j >= m) break;
            if(b[j] < a[i]){
                swap(a[k],b[j]);
                k--;
                j++;
            }else{
                i++;
            }
        }
        
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        
        
    }
};