class Solution {
private:
    int max_width;
    string findLine(int i, int j, int eachPitSpace, int extraPitSpace, vector<string> &words){

        string line;

        for(int k=i; k < j;k++){
            line += words[k];

            if(k==j-1) continue; // no space after last word of the line 

            for(int z = 1; z<=eachPitSpace;z++){
                line += ' ';
            }

            if(extraPitSpace > 0){
                line+= ' ';
                extraPitSpace--;
            }
        }
        while(line.length() < max_width){
            line +=' ';
        }
        return line;
    }

public:

    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int n = words.size();
        vector<string> result;

        max_width = maxWidth;
        int i =0;
        while(i<n){
            int lettersCnt = words[i].length();
            int j = i+1;
            int pits= 0;

            while(j<n && words[j].length() + 1 + pits + lettersCnt <= max_width){
                lettersCnt += words[j].length();
                pits++;
                j++;
            }

            int remainingPits = max_width - lettersCnt;
            int eachPitSpace = pits == 0 ? pits : remainingPits / pits;
            int extraPitSpace = pits == 0 ? pits : remainingPits % pits;

            if(j == n){     //Last line - left justified
                eachPitSpace = 1;
                extraPitSpace = 0;
            }
            result.push_back(findLine(i,j,eachPitSpace,extraPitSpace, words));
            i = j;
        }

        return result;
    }
};