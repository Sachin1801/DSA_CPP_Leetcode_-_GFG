class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> left(n), right(n);

        int curr =1;
        left[0]=1;
        right[n-1]=1;
        for(int i=1;i<n;i++){
            if(ratings[i-1] < ratings[i]){
                curr++;
                left[i] = curr;
            }else{
                curr = 1;
                left[i] =curr;
            }
        }
        curr =1;
        for(int i=n-2;i>=0;i--){
            if(ratings[i] > ratings[i+1]){
                curr++;
                right[i]=curr;
            }else{
                curr = 1;
                right[i]=curr;
            }
        }
        int ans =0;
        for(int i=0;i<n;i++){
            ans += max(left[i],right[i]);
        }
        return ans;
    }
};