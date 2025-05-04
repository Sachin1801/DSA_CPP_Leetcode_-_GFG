

struct pair_hash {
    size_t operator()(const pair<int, int>& p) const {
        return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);  // or use boost::hash_combine
    }
};


class Solution {
private:
    void convert(pair<int,int> &a){
        if(a.second < a.first) swap(a.second,a.first);
    }

public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        unordered_map<pair<int,int>, int, pair_hash> freq;
        int result =0;
        for(int i=0;i<dominoes.size();i++){
            pair<int,int> p = {dominoes[i][0],dominoes[i][1]};
            convert(p);
            if(freq.find(p)==freq.end()){
                freq[p]=1;
            }else if(freq.find(p)!=freq.end()){
                result += freq[p];
                freq[p]++;
            }
        }
        return result;
    }
};