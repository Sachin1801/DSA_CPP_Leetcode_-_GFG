class Solution {
private:
    bool isValid(string &sq, int pos, int sum, int &val){
        if(pos >=sq.size()){
            return sum==val;
        }

        for(int i=0;i+pos <sq.size();++i){
            int curr_val = stoi(sq.substr(pos,i+1));
            if(isValid(sq,i+pos+1, sum+curr_val,val))
                return true;
        }
        return false;
    }

public:
    int punishmentNumber(int n) {
        int p_no= 1;
        for(int i=2;i<=n;i++){
            string sq = to_string(i*i);
            if(isValid(sq,0,0,i))
                p_no+= i*i;
        }
        return p_no;
    }
};