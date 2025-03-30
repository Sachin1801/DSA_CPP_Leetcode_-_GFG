class Solution {
public:
    vector<int> partitionLabels(string s) {
        if(s.length()==1) return {1};
        vector<vector<int>> positions(26);
        int n = s.size();
        for(int i=0;i<n;i++){
            positions[s[i]-'a'].push_back(i);
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<>> minheap;

        for(int i=0;i<26;i++){
            if(positions[i].size()==0)continue;
            else{
                int start = positions[i][0];
                int end = positions[i].back();
                minheap.push({start,end});
            }
        }
        vector<int> result;
        int currmin = -1,currmax=-1;
        while(!minheap.empty()){
            auto [newmin, newmax] = minheap.top();
            minheap.pop();
            if(currmin==-1 && currmax==-1){
                currmin = newmin;
                currmax = newmax;
                continue;
            }
            else{
                if(newmin < currmax){
                    currmin = min(currmin,newmin);
                    currmax = max(currmax,newmax);
                }else{
                    result.push_back(currmax-currmin+1);
                    currmin = newmin;
                    currmax = newmax;
                }
            }
        }
        result.push_back(currmax-currmin+1);
        return result;
    }
};