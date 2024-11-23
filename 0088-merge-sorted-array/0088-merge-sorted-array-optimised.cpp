class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = (m+n)-1;
        int j= m-1;
        int k = n-1;
        while(k>=0)
        {
            if(j>=0 and nums1[j]>nums2[k])
            {
                nums1[i]= nums1[j];
                j--;
                i--;
            }
            else
            {
                nums1[i] = nums2[k];
                k--;
                i--;
            }
        }
    }
};