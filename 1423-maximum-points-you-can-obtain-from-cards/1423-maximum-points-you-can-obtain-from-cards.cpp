class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        if(k==cardPoints.size())
            return accumulate(cardPoints.begin(),cardPoints.end(),0);
        int j = cardPoints.size()-1;
        int lsum =0;
        int i;
        for(i=0;i<k;i++)
            lsum += cardPoints[i];
        i--;
        int ans =lsum;
        while(i>=0){
            lsum = lsum - cardPoints[i--] + cardPoints[j--];
            ans = max(lsum,ans);
        }
        return ans;
    }
};