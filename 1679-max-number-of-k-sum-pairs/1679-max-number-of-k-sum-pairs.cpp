class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        int n= nums.size();
        for(int i=0;i<n;i++){
            m[nums[i]]++;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(m[nums[i]]<=0)
                continue;
            else{
                m[nums[i]]--;
                int rem = k - nums[i];
                if(m.find(rem)!=m.end()){
                    if(m[rem]>=1){
                        m[rem]--;
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};