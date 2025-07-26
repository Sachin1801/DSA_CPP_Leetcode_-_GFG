class Solution {
  public:
  
    int minJumps(vector<int>& arr) {
        // code here
        
        if(arr[0]==0) return -1;
        
        int currReach = 0;
        int maxReach = 0;
        int jump = 0;
        
        for(int i =0;i<arr.size();i++){
            maxReach = max(maxReach, i+arr[i]);
            if(maxReach >=arr.size()-1) return jump+1;
            if(currReach == i){
                if(maxReach > i){
                    currReach = maxReach;
                    jump++;
                }else{
                    return -1;
                }
            }
        }
        return -1;
    }
};
