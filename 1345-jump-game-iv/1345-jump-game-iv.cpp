class Solution {

public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if(n==1) return 0;

        unordered_map<int,vector<int>> sameVal;

        for(int i =0; i< n; i++){
            sameVal[arr[i]].push_back(i);
        }

        vector<int> minDist(n,-1);
        minDist[0] = 0;
        queue<int> q;
        q.push(0);

        while(!q.empty()){
            int i = q.front(); q.pop();

            if(i +1 < n && minDist[i+1] == -1){
                minDist[i+1] = 1 + minDist[i];
                if(i+1 == n-1) return minDist[n-1];
                q.push(i+1);
            }
            if(i-1 >=0 && minDist[i-1] == -1){
                minDist[i-1] = 1 + minDist[i];
                q.push(i-1);
            }

            if(sameVal.count(arr[i])){
                for(int x: sameVal[arr[i]]){
                    if(minDist[x] == -1){
                        minDist[x] = 1 + minDist[i];
                        if(x == n-1 ) return minDist[n-1];
                        q.push(x);
                    }
                }
                sameVal.erase(arr[i]);
            }
        }
        return minDist[n-1];
        // return minDist[n-1];
    }
};