class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int prev= -1;
        int ops = INT_MAX;
        int n= blocks.length();
        int black=0,white=0;
        for(int i=0;i<n;i++){
            if(prev!=-1){
                if(blocks[prev]=='B') black--;
                else white--;
            }
            if(blocks[i]=='B') black++;
            else white++;
            int length = prev == -1 ? i+1 : i-prev ;
            if(length==k){
                ops = min(ops, white);
                prev++;
            }
        }
        return ops;
    }
};