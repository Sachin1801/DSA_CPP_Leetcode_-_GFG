// Last updated: 12/14/2025, 4:17:03 PM
class Solution {
private:
    long long myPow(long long x, long long n) {
        long long ans = 1;
        while(n){
            if(n&1) ans = (ans*x)%1000000007;
            x = (x*x)%1000000007;
            n = n>>1;
        }  
        return ans;
    }

public:
    int countGoodNumbers(long long n) {
        long long oddmultiple ;
        long long evenmultiple ;
        if(n&1){
            oddmultiple = myPow(5,(n/2)+1);
            evenmultiple = myPow(4,(n/2)) ;
        }else{
            oddmultiple = myPow(5,(n/2)) ;
            evenmultiple = myPow(4,(n/2));
        }
        return ((oddmultiple * evenmultiple)%1000000007);
    }
};