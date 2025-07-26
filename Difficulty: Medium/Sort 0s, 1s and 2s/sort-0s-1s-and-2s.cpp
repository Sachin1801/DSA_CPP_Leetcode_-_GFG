class Solution {
  public:
    void sort012(vector<int>& arr) {
        // code here
        vector<int> temp(3,0);
        
        for(int x: arr){
            temp[x]++;
        }
        int j =0;
        for(int i=0;i<temp.size();i++){
            for(int k = 0; k< temp[i];k++){
                arr[j++] = i;
            }
        }
        
    }
};