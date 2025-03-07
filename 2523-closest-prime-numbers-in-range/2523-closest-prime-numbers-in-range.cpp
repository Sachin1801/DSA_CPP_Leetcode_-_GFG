class Solution {
private:
    bool isPrime(int n){
        if(n<=1) return false;
        
        for(int i =2; i*i <=n;i++){
            if(n%i==0) return false;
        }
        return true;
    }

public:
    vector<int> closestPrimes(int left, int right) {
        vector<int> ans(2,-1);
        int sec_last = -1;
        int last = -1;
        int min_diff = INT_MAX;
        for(int i = left;i<=right;i++){
            if(isPrime(i)){
                if(sec_last==-1){
                    sec_last = i; 
                }
                else last= i;
                if(sec_last!=-1 && last != -1){
                    if(last-sec_last < min_diff){
                        min_diff = min(min_diff,last-sec_last);
                        ans[0] = sec_last;
                        ans[1]=last;
                    }
                    sec_last = last;
                    last = -1;
                }
            }
        }
        return ans;        
    }
};