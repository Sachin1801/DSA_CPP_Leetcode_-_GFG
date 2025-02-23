class Solution {
private:
    int count(long long curr, long long n){
        long long res = 0;
        long long nbr = curr +1;
        while(curr <=n){
            res += min(nbr,n+1) - curr;
            curr *=10;
            nbr *=10;
        }
        return res;
    }

public:
    int findKthNumber(int n, int k) {
        int curr =1;
        int i =1;

        while(i<k){
            int steps = count(curr,n);
            if(i + steps <=k){
                curr +=1;
                i += steps;
            }
            else{
                curr *= 10;
                i++;
            }
        }


        return curr;
    }
};