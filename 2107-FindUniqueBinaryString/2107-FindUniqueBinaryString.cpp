// Last updated: 12/14/2025, 4:17:01 PM
class Solution {
private:
    string flip(string s, int i){
        if(s[i]=='0') s[i]='1';
        else s[i]='0';
        return s;
    }

public:
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<string> s;
        for(int i=0;i<nums.size();i++){
            s.insert(nums[i]);
        }
        string current;
        for(int i=0;i<nums.size();i++){
            current = nums[i];
            for(int j=current.length()-1; j>=0;j--){
                string temp = flip(current,j);
                if(s.find(temp)==s.end()) return temp;
            }
        }
        return current;
    }
};