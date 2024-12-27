class Solution {

public:
    double myPow(double x, int n) {
        if(n==0) return double(1);
        if(n==INT_MIN) x *= x, n = n/2;

        //if n is negative
        if(n<0) n *= -1, x = double(1)/x;

        double ans = 1;
        while(n){
            if(n&1) ans *= x;
            x*=x;
            n = n>>1;
        }  
        return ans;
    }
};