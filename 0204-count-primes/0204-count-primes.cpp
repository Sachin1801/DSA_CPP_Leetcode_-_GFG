class Solution {
private:
    void set_multiples_false(vector<int> &primes, int val){
        for(int i=val;i<primes.size();i+=val){
            primes[i]=0;
        }
    }

public:
    int countPrimes(int n) {
        if(n==0 || n==1) return 0;
        vector<int> prime(n+1,1);
        prime[0]=0;
        prime[1]=0;
        int ans =0;
        for(int i=2;i<n;i++){
            if(prime[i]==1){
                ans++;
                set_multiples_false(prime,i);
            }
        }
        return ans;
    }
};