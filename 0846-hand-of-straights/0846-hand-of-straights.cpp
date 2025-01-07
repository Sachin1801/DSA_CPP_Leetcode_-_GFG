class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize !=0)
            return false;
        unordered_map<int,int> m;
        for(int i=0;i<hand.size();i++){
            m[hand[i]]++;
        }
        priority_queue<int,vector<int>, greater<int>> pq;
        for(auto ele: m){
            pq.push(ele.first);
        }
        while(!pq.empty()){
            int currgrpsize =0;
            vector<int> temp;
            vector<int> currbuffer;
            while(currgrpsize < groupSize){
                int ctop = pq.top();
                pq.pop();
                if(currgrpsize>0 and currbuffer.back()!= ctop-1)
                    return false;
                currbuffer.push_back(ctop);
                m[ctop]--;
                if(m[ctop]>0)
                    temp.push_back(ctop);
                currgrpsize++;
            }
            for(auto ele: temp)
                pq.push(ele);
        }
        return true;
    }
};