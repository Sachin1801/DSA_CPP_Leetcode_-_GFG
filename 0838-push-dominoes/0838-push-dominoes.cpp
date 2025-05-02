class Domino{
    void doubleDominoPush(int last_r, int pos,string &dominoes){
        while(last_r < pos){
            dominoes[last_r++]='R';
            dominoes[pos--]='L';
        }
    }

    void leftDominoPush(int start, int end, string &dominoes){
        while(start<=end){
            dominoes[start++]='L';
        }
    }

    void rightDominoPush(int last_r, int pos, string &dominoes){
        while(last_r <=pos){
            dominoes[last_r++]='R';
        }
    }

    friend class Solution;
};


class Solution {
public:
    string pushDominoes(string dominoes) {
        Domino newDomino;
        int last_r = -1, last_l = -1;
        int n = dominoes.size();

        for(int pos = 0; pos < n; pos++){
            if(dominoes[pos]=='L'){
                if(last_r > last_l){
                    newDomino.doubleDominoPush(last_r,pos,dominoes);
                }
                else if((last_l > last_r) || last_l ==-1){
                    newDomino.leftDominoPush(last_l+1,pos,dominoes);
                } 
                last_l = pos;
            }else if(dominoes[pos]=='R'){
                if(last_r > last_l){
                    newDomino.rightDominoPush(last_r,pos,dominoes);
                }
                last_r = pos;
            }
        }
        if(last_r > last_l) newDomino.rightDominoPush(last_r,n-1,dominoes);
        return dominoes;
    }
};