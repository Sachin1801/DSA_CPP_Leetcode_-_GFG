// Last updated: 12/14/2025, 4:15:25 PM
class Solution {
private:
    bool canTransform(vector<int> &nums,vector<vector<int>>& queries, int mid ){
        int n = nums.size();

        vector<int> diff(n+1,0);

        for(int i=0;i<mid;i++){
            diff[queries[i][0]] += queries[i][2];
            diff[queries[i][1]+1] -= queries[i][2];
        }
        int sum =0;
        for(int i=0;i<diff.size();i++){
            sum += diff[i];
            if(i< n && sum < nums[i]) return false;
        }
        return true;
    }

public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), left = 0, right = queries.size();

        //check for all queries
        if(!canTransform(nums,queries,right)) return -1;

        while(left <=right){
            int mid = left + (right-left)/2;
            if(canTransform(nums,queries,mid)){
                right = mid-1;
            }
            else left = mid+1;
        }
        return left;
    }
};