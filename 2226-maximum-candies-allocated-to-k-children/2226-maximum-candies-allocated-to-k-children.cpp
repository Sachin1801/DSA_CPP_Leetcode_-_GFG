class Solution {
private:
    bool check(vector<int> &candy, int mid, long long k){
        long long currk=0;
        for(int i=candy.size()-1;i>=0;i--){
            if(candy[i] < mid && currk < k) break;
            if(candy[i]>=mid){
                currk += candy[i]/mid;
            } 
            if(currk >=k) return true;
        }
        return false;
    }

public:
    int maximumCandies(vector<int>& candies, long long k) {
        int left = 1;
        int right = *max_element(candies.begin(),candies.end());
        sort(candies.begin(),candies.end());
        int ans = 0;
        while(left <=right){
            int mid = left + (right-left)/2;
            if(check(candies,mid,k)){
                ans = mid;
                left = mid+1;  
            } 
            else right = mid-1;
        }
        return ans;
    }
};