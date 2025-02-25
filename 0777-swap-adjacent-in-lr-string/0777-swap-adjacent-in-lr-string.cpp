class Solution {
public:
    bool canTransform(string start, string result) {
        vector<pair<char,int>> v1;
        vector<pair<char,int>> v2;

        int n = start.length();
        for(int i=0;i<n;i++){
            if(start[i]!='X') v1.push_back({start[i],i});
            if(result[i]!='X') v2.push_back({result[i],i});
        }
        if(v1.size()!=v2.size())
            return false;

        for(int i=0;i<v1.size();i++){
            auto p1 = v1[i];
            auto p2 = v2[i];

            if(p1.first=='L' && p2.first=='L'){
                if(p1.second < p2.second)
                    return false;
            }
            else if(p1.first =='R' && p2.first=='R'){
                if(p1.second > p2.second ) return false;
            }
            else return false;
        }
        return true;
    }
};