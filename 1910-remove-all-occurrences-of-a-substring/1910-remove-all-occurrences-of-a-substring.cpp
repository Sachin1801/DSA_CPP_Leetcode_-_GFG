class Solution {
public:
    string removeOccurrences(string s, string part) {
        if(part.size() > s.size())
            return s;
        size_t pos = s.find(part);

        while(pos != string::npos){
            s.erase(pos,part.length());
            pos = s.find(part);
        }
        return s;
    }
};