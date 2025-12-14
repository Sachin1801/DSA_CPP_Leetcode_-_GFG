// Last updated: 12/14/2025, 4:16:46 PM
class Solution {
public:
    char repeatedCharacter(string s) {
        int freq[26]={0};
        for(int i=0;i<s.length();i++)
        {
            freq[s[i]-'a']++;
            if(freq[s[i]-'a']>1)
            {
                return s[i];
            }
        }
        return 'z';
    }
};