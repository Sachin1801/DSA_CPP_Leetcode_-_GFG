class Solution {
public:
    int hIndex(vector<int>& citations) {
        int h_index = 1;
        sort(citations.begin(), citations.end());
        
        for(int i=0;i<citations.size();i++){
            cout<<citations[i] <<" ";
        }
        cout<< endl;

        for(int i= citations.size()-1; i>=0; i--){
            if(citations[i] >= h_index) h_index++;
            else break;
        }
        return h_index-1;
    }
};