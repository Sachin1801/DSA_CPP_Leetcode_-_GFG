class Solution {
public:

    int requiredtime(vector<int> &piles, int rate, int h){
    int hours=0;
        for(int i=0;i<piles.size();++i){
            if(hours>h){
                break;
            }
            if(piles[i]%rate==0){
                hours += piles[i]/rate;
            }else{
                hours += (piles[i]/rate) +1;
            }
        }
        return hours;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int maxele = 0;
        for(int i=0;i<piles.size();++i){
            if(piles[i]>maxele)
                maxele = max(maxele,piles[i]);
        }
        int low =1,high = maxele;
        int ans =maxele;
        int hours=0;
        while(low<=high){
            int mid = (low+high)/2;
            hours = requiredtime(piles,mid,h);
            if(hours <=h){
                ans = min(ans,mid);
                high = mid - 1;
            }else{
                low = mid +1 ;
            }
        }
        return ans;
    }
};