class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> leftmax(n,-1);
        vector<int> rightmax(n,-1);
        int i=0,j=n-1;
        int Leftmax = -1;
        int Rightmax=-1;
        while(i<n and j>=0){
            if(height[i]>Leftmax)
                Leftmax=height[i];
            if(height[j]>Rightmax)
                Rightmax = height[j];
            leftmax[i++]=Leftmax;
            rightmax[j--]=Rightmax;
        }
        j=0;
        for(i=0; i<n;i++){
            j += min(leftmax[i],rightmax[i])-height[i];
        }

        return j;
    }
};