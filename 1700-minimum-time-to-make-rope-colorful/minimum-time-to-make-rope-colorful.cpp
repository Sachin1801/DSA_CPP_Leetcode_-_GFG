class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        if(neededTime.size() == 1) return 0;


        int ans = 0;
        int n = colors.length();

        for(int i=0;i<n-1;i++){
            //if the next and the current character are same
            if(colors[i]==colors[i+1]){
                int j = i+1;
                int minTime = neededTime[i];
                // minHeap.push(neededTime[i]);
                while(j<n && colors[j]==colors[i]){
                    if(neededTime[j] > minTime){
                        // cout<<"Adding old minTime = "<<minTime<<" ";
                        ans += minTime;
                        minTime = neededTime[j];
                        // cout<<"New MinTime = "<<minTime<<endl;
                    }else{
                        // cout<<"Addding time = "<< neededTime[j];
                        ans += neededTime[j];
                    }
                    j++;
                }
                i = j-1;
            }
        }
        return ans;
    }
};