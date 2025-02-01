class Solution {
    set<char> st = {'a','e','i','o','u','A','E','I','O','U'};
public:
    string reverseVowels(string s) {
        int n = s.length();
        int i =0,j= n-1;
        while(i<j){
            while(st.find(s[i])==st.end() && i < j)
                i++;
            while(st.find(s[j])==st.end() && i < j)
                j--;
            swap(s[i++],s[j--]);
        }
        return s;
    }
};