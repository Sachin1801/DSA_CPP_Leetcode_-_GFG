class Solution {
public:

    bool findPossibleBouquet(vector<int> &arr, int mid, int k, int m){
        int cnt = 0;
        int possible =0;
        for(int i=0;i<arr.size();++i){
            if(arr[i]<=mid){
                cnt++;
            }else{
                possible += cnt/k;
                cnt = 0;
            }
        }
        possible += cnt/k;
        return possible >=m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        long long val = m * 1LL * k * 1LL;
        if(val>bloomDay.size())
            return -1;

        //find answer range - between minelement and maxelement in array
        int maxele = INT_MIN;
        int minele = INT_MAX;
        for(int i=0;i<bloomDay.size();++i){
            if(bloomDay[i]>maxele){
                maxele = max(maxele,bloomDay[i]);
            }
            if(bloomDay[i]<minele){
                minele = min(minele,bloomDay[i]);
            }
        }

        while(minele <= maxele ){
            int mid = (maxele + minele)/2;
            bool possible= findPossibleBouquet(bloomDay,mid,k, m);
            if(possible){
                maxele = mid - 1;
            }else{
                minele = mid + 1;
            }
        }
        return minele;
    }
};