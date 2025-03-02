class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        vector<vector<int>> ans;
        int i=0,j=0,n1= nums1.size(),n2= nums2.size();
        while(i< n1 && j < n2){
            int id1 = nums1[i][0];
            int id2 = nums2[j][0];

            int val1 = nums1[i][1];
            int val2 = nums2[j][1];
            
            if(id1==id2){
                ans.push_back({id1,val1+val2});
                i++;
                j++;
            }
            else if(id1 > id2){
                ans.push_back({id2,val2});
                j++;
            }else{
                ans.push_back({id1,val1});
                i++;
            }
        }
        while(i < n1){
            ans.push_back({nums1[i][0],nums1[i][1]});
            i++;
        }
        while(j < n2){
            ans.push_back({nums2[j][0],nums2[j][1]});
            j++;
        }
        return ans;
    }
};