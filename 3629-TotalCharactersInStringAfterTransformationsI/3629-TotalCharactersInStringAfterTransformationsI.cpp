// Last updated: 12/14/2025, 4:15:28 PM
class Solution {
private:
    const int MOD = 1e9+7;

    int mod_ans(int a, int b){
        a %=MOD;
        b%=MOD;
        return (((a+b)%MOD)+MOD)%MOD;
    }

public:
    int lengthAfterTransformations(string s, int t) {
        //step 1: count the frequency
        vector<int> nums(26,0);
        for(char ch: s){
            nums[ch-'a']++;
        }

        //step 2: perform t operations
        while(t--){
            vector<int> curr(26,0);
            //make transformations to string
            for(int j=0;j<26;j++){
                if(j==25 && nums[j]>0){
                    curr[0] = mod_ans(curr[0],nums[j]);
                    curr[1] = mod_ans(curr[1],nums[j]);
                }else {
                    if(j<25) curr[j+1] = mod_ans(curr[j+1],nums[j]);
                }
            }
            //step 4: update frequency
            for(int i=0;i<26;i++){
                nums[i]=curr[i];
            }
        }
        int ans = 0;
        for(int i=0;i<26;i++){
            ans = mod_ans(ans,nums[i]);
        }
        return (int)ans;
    }
};