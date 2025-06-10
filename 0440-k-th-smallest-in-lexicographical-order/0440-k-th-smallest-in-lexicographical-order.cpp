class Solution {
private:
    int Count(long curr, long next, int n){
        int CountNum = 0;

        while(curr<=n){
            CountNum += (next - curr);

            curr *=10;
            next *=10;
            next = min(next, (long)n+1);
        }
        return CountNum;
    }

public:
    int findKthNumber(int n, int k) {
        if(k==1) return 1;

        int curr =1 ;
        k-=1;
        while(k>0){
            int count = Count(curr,curr+1,n);

            if(count <= k){
                k-= count;
                curr++;
            }else{
                curr *=10;
                k--;
            }
        }
        return curr;
    }
};