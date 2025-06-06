class Solution {
private:
    char smallest_char_possible(unordered_map<char,vector<char>>& eq_info, char curr_ch){
        unordered_set<char> unique;
        queue<char> q;
        q.push(curr_ch);
        unique.insert(curr_ch);
        char temp= curr_ch;
        while(!q.empty()){
            char top= q.front();
            q.pop();
            for(auto ch: eq_info[top]){
                temp = min(temp,ch);
                if(unique.count(ch)==0){
                    q.push(ch);
                    unique.insert(ch);
                }
            }
        }
        return temp;
    }

public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n = s1.length();

        unordered_map<char,vector<char>> eq_info;
        for(int i=0;i<n;i++){ //O(n)
            eq_info[s1[i]].push_back(s2[i]);
            eq_info[s2[i]].push_back(s1[i]);
        }

        for(int i=0;i<baseStr.length();i++){ //O(N)
            char ch = smallest_char_possible(eq_info,baseStr[i]);
            baseStr[i] = ch;
        }
        return baseStr;
    }
};