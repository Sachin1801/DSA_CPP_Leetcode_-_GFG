class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int min_rotations=-1, count_tops=INT_MAX, count_bottoms= INT_MAX;
        for(int face_value=1; face_value<=6;face_value++){
            int top_swaps=0;
            for(int i=0;i<tops.size();i++){
                if(tops[i]!=face_value && bottoms[i]!=face_value){
                    top_swaps = INT_MAX;
                    break;
                }
                else if(tops[i]==face_value) continue;
                else if(bottoms[i]==face_value) top_swaps++;
            }
            if(top_swaps==INT_MAX) continue;
            else{
                count_tops = top_swaps;
                int bottom_swap=0;
                for(int i=0;i<tops.size();i++){
                    if(bottoms[i]==face_value) continue;
                    else if(tops[i]==face_value && bottoms[i]!=face_value) bottom_swap++;
                }
                count_bottoms = bottom_swap;
            }
            min_rotations = min(count_tops, count_bottoms);
        }
        return min_rotations;
    }
};