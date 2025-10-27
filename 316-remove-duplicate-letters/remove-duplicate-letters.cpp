class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> freq(26,0);
        vector<bool> inStack(26,false);

        for(char c:s){
            freq[c-'a']++;
        }
        string result = "";
        for(char c: s){
            int idx = c - 'a';
            freq[idx]--;
            if(inStack[idx]) continue;

            while(!result.empty() && result.back() > c && freq[result.back()-'a'] > 0){
                inStack[result.back()-'a'] = false;
                result.pop_back();
            }

            result += c;
            inStack[idx] = true;
        }
        return result;
    }
};