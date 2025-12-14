// Last updated: 12/14/2025, 4:17:05 PM
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