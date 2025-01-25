class Solution {
    private:
        //N,S,E,W
        vector<pair<int,int>> direction = {{0,-1},{0,1},{1,0},{-1,0}}; 
public:
    bool isPathCrossing(string path) {
        if(path.size()==0)
            return true;
        pair<int,int> src = {0,0};
        set<pair<int,int>> s;
        s.insert({0,0});
        for(int i=0;i<path.size();i++){
            char ch = path[i];
            if(ch=='N'){
                src = {src.first + direction[0].first, src.second+ direction[0].second};
            }
            else if(ch=='S'){
                src = {src.first + direction[1].first, src.second+ direction[1].second};
            }
            else if(ch=='E'){
                src = {src.first + direction[2].first, src.second+ direction[2].second};
            }
            else{
                src = {src.first + direction[3].first, src.second+ direction[3].second};
            }
            if(s.find(src)!=s.end())
                return true;
            else
                s.insert(src);
        }
        return false;

    }
};