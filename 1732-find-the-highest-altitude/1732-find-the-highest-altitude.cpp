class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int csum=0;
        int msum=INT_MIN;
        int n = gain.size();
        vector<int> prefix(n+1);
        prefix[0]=0;
        for(int i=0;i<n;i++){
            prefix[i+1] = prefix[i]+gain[i];
                      
        }
        for(int i=0;i<n+1;i++){
            if(msum < prefix[i])
                msum = max(msum,prefix[i]);
        }
        return msum;
    }
};