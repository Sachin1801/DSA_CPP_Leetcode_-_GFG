class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int csum=0;
        int msum=INT_MIN;
        int n = gain.size();
        vector<int> prefix(n+1);
        prefix[0]=0;
        for(int i=0;i<n;i++){
            if(msum < csum )
                msum = max(csum,msum);
            csum= csum +gain[i];
        }
        return max(msum,csum);
    }
};