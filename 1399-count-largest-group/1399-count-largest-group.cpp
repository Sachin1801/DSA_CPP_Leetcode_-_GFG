class Solution {
private:
    int calc_sum(int n){
        int sum = 0;
        while(n>0){
            int rem = n%10;
            sum += rem;
            n /=10;
        }
        return sum;
    }

public:
    int countLargestGroup(int n) {
        if(n<=9) return n;
        map<int,int> freq;
        int max_size = 1;
        for(int i=1;i<=n;i++){
            int sum = calc_sum(i);
            freq[sum]++;
            max_size = max(max_size, freq[sum]);
        }
        int ans = 0;
        
        for(auto it= freq.begin(); it!=freq.end();it++){
            if(it->second == max_size) ans++; 
        }
        return ans;
    }
};