class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> arr(26,0);
        for(int i=0;i<s.length();i++){
            arr[s[i]-'a']++;
        }
        for(int i=0;i<t.length();i++){
            if(arr[t[i]-'a']==0){
                return false;
            }else{
                arr[t[i]-'a']--;
            }
        }
        int val = accumulate(arr.begin(),arr.end(),0);
        if(val>0)
            return false;
        return true;
    }
};