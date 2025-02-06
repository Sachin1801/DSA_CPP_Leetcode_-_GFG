class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int,int> m;
        int n = nums.size();
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(i==j)
                    continue;
                int prod = nums[i]*nums[j];
                m[prod]++;
            }
        }
        int ans = 0;
        for(auto& [prod,vec]: m){
            if(vec>1){
                int count = 8*((vec*(vec-1))/2);
                ans+= count;
            }
        } 
        return ans;
    }
};