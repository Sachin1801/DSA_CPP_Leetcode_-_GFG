class Solution {
private:
    bool check(vector<int> &net, int i){
        int n = net.size();
        int start = i;
        int gas = net[i];
        i = (i+1)%n;
        while(start!=i ){
            gas+= net[i];
            if(gas < 0) return false;
            i = (i+1)%n;
        }
        return true;
    }

public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        if(n==1){
            if(gas[0] >= cost[0]) return 0;
            else return -1;
        }
        vector<int> net(n);
        for(int i=0;i<n;i++){
            net[i] = gas[i] - cost[i];
        }
        if(accumulate(net.begin(),net.end(),0) < 0) return -1;
        queue<int> candidates;
        for(int i=0;i<n;i++){
            if(net[i] >0) candidates.push(i);
        }
        int ans = -1;
        while(!candidates.empty()){
            int fr = candidates.front();
            candidates.pop();
            if(check(net,fr)){
                ans = fr;
                break;
            }
        }
        return ans;
    }
};