#include<cstring>
string keypad[] = {"","" , "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
class Solution {
    
    
public:
    
    vector<string> ans;
    
    void phone_keypad(string in, string out, int i)
{
    // base case
    if (in[i] == '\0')
    {
        ans.push_back(out);
        return;
    }

    // rec case

    int cd = in[i] - '0'; // cd - current digit

    if (cd == 0 or cd == 1)
    {
        phone_keypad(in, out, i + 1);
    }

    for (int k = 0; k < keypad[cd].size(); k++)
    {
        phone_keypad(in, out + keypad[cd][k], i + 1);
    }
    return;
}
    
    vector<string> letterCombinations(string digits) {

    if(digits.length()==0)
    {
        return ans;
    }
    string output;

    phone_keypad(digits, output, 0);
        
    return ans;

    }
};