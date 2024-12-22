typedef pair<int,char> pi;

class Solution {
public:
    string frequencySort(string s) {
        multimap<int,char> mm;
        unordered_map<char,int> m;
        for(int i=0;i<s.length();i++){
            m[s[i]]++;
        }
        for( auto& x: m){
            mm.insert({x.second,x.first});
        }
        string ans ="";
        for(auto it = mm.rbegin(); it!=mm.rend();it++){
            ans += string(it->first,it->second);
        }
        return ans;
    }
};