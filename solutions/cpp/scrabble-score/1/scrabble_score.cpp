#include "scrabble_score.h"
#include <string>

namespace scrabble_score {

// TODO: add your solution here
    int score(const string& word){
        int finalScore{0};

        for(char ch: word){
            ch = toupper(ch);
            if(ch == 'A' || ch == 'E' || ch == 'I' || ch=='O' || ch == 'U' || ch == 'L' || ch == 'N' || ch == 'R' || ch == 'S' || ch == 'T' ){
                finalScore += 1;
            }else if(ch == 'D' || ch == 'G'){
                finalScore += 2;
            }else if(ch == 'B' || ch == 'C' || ch == 'M' || ch=='P'){
                finalScore += 3;
            }else if(ch == 'F' || ch == 'H' || ch == 'V' || ch=='W' || ch == 'Y' ){
                finalScore += 4;
            }else if(ch =='K'){
                finalScore += 5;
            }else if(ch=='J' || ch=='X'){
                finalScore += 8;
            }else{
                finalScore += 10;
            }
        } 
        return finalScore;
    }

}  // namespace scrabble_score
