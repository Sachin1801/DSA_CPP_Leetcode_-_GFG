// Last updated: 12/14/2025, 4:15:56 PM
class Solution {
public:
    int minMaxDifference(int num) {
        char max_idx,min_idx;
        string n = to_string(num);
        for(int i =0;i<n.length();i++){
            if(n[i]=='9'){
                max_idx = n[i];
            }else if(n[i]!='9'){
                max_idx = n[i];
                break;
            } 
        }
        min_idx = n[0];
        string Max = n;
        for(int i =0;i<n.length();i++){
            if(Max[i]==max_idx){
                Max[i] = '9';
            } 
        }
        string Min = n;
        for(int i=0;i<n.length();i++){
            if(Min[i]==min_idx){
                Min[i] = '0';
            }
        }
        int ans = stoi(Max) - stoi(Min);
        return ans;
    }
};