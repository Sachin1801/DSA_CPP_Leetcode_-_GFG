// Last updated: 12/14/2025, 4:16:48 PM
#define ll long long
class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> ansvec;
        sort(potions.begin(),potions.end());
        for(int i=0;i<spells.size();i++)
        {
            long double temp=  double(success) /  double(spells[i]);
            int s=0,e=potions.size()-1;
            int ans=0;
            while(s<=e)
            {
                int mid = (s+e)/2;
                if(potions[mid]>=temp)
                {
                    ans = potions.size()-mid;
                    e= mid-1;
                }
                else s=mid+1;
            }
            ansvec.push_back(ans);
        }
        return ansvec;
    }
};