class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(vector<int>& start, vector<int>& end) {
        // Your code hxere
        
        //sort the end vector based on increasing end times
        // and store pointer to corresponding start time bucket
        
        int n = start.size();
        vector<pair<int,int*>> newEnd(n);
        //make the new vector
        for(int i=0;i<n;i++){
            newEnd[i] = {end[i],&start[i]};
        }
        
        //sort the newEnd based on endtime
        sort(newEnd.begin(),newEnd.end(),[](pair<int,int*> p1, pair<int,int*> p2){
           return p1.first < p2.first;
        });
        
        
        int ans = 0;
        
        int lastEnd = -1;
        for(int i=0;i<n;i++){
            int startTime = *(newEnd[i].second);
            int endTime = newEnd[i].first;
            
            if(lastEnd !=-1){
                if(startTime > lastEnd){
                    ans++;
                    lastEnd = endTime;
                }
            }
            else{
                ans++;
                lastEnd  = endTime;
            }
        }
        return ans;
    }
};