class Solution {
public:
    int minBitFlips(int start, int goal) {
        if(start == goal ) return 0;
        int smal= min(start,goal);
        int lar = max(start, goal);
        int cnt =0;
        while(lar>0){
            if((lar&1) && !(smal&1))
                cnt++;
            else if(!(lar&1) && (smal&1))
                cnt++;
            lar = lar>>1;
            smal = smal>>1;
        }
        return cnt;
    }
};