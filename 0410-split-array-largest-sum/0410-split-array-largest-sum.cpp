class Solution {

    private:

    int test(vector<int> &arr, int mid , int m){
        int splits = 1;
        long long sum = 0;
        for(int i=0;i<arr.size();++i){
            if(sum + arr[i] <= mid){
                sum += arr[i];
            }else{
                splits++;
                sum = arr[i];
            }
            if(splits > m)
                return splits;
        }
        return splits;
    }

    int findsplits(vector<int> &arr, int n, int m){
        if(m>n)
            return -1;
        int low = *max_element(arr.begin(),arr.end());
        int high = accumulate(arr.begin(),arr.end(),0);
        while(low<=high){
            int mid = (low+high)/2;
            int splits = test(arr,mid,m);
            if(splits>m){
                low = mid + 1;
            }else{
                high = mid -1;
            }
        }
        return low;
    }

public:
    int splitArray(vector<int>& nums, int k) {
        return findsplits(nums,nums.size(),k);
    }
};