// Last updated: 12/14/2025, 4:17:00 PM
#define ll long long 
class Solution {
public:

    ll countKaroProducts(vector<int>& a, vector<int>& b, ll mid)
    {
        ll totalNumbersLessThanMid =0 ;
        for(auto el : a)
        {
            ll cnt =0;
            if(el>=0)
            {
                ll s = 0;
                ll e = b.size()-1;
                while(s<=e)
                {
                    ll m = (s+e)/2;
                    if((ll)((ll)el*(ll)b[m]) <= mid)
                    {
                        cnt = m + 1;
                        s = m+1;
                    }
                    else{
                        e = m-1;
                    }
                }
                totalNumbersLessThanMid += cnt;
            }
            else{
                ll s = 0;
                ll e = b.size()-1;
                
                while(s<=e)
                {
                    ll m = (s+e)/2;
                    if((ll)((ll)el*(ll)b[m])<=mid)
                    {
                        cnt = b.size() - m;
                        e = m-1;
                    }
                    else{
                        s = m + 1;
                    }
                }
                totalNumbersLessThanMid += cnt;
            }
        }
        return totalNumbersLessThanMid;
    }

    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        ll s = -1e10;
        ll e = 1e10;
        ll ans ;
        while(s<=e) // Time complexity (O(log(2*10^10)))
        {
            ll mid = (s+e)/2;
            if(countKaroProducts(nums1,nums2,mid)>=k)
            {
                ans = mid ;
                e = mid-1;
            }
            else{
                s = mid+1;
            }
        }
        return ans;
    }
};