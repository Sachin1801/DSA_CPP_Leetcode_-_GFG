#define MOD 1000000007

class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        int ans =0;
        int oddcnt = 0;
        int evencnt =0;
        vector<int> prefixsum;
        for(int i=0;i<n;i++){
            if(i==0) prefixsum.push_back(arr[i]);
            else prefixsum.push_back(prefixsum[i-1]+arr[i]);
            if(prefixsum[i]&1){
                oddcnt++;
                ans = ans + 1 + evencnt;
            }else{
                evencnt++;
                ans += oddcnt;
            }
        }
        return ans;
    }
};