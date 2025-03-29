class Solution {
public:
    int uniqueLetterString(string s) {
        int n = s.size();
        vector<vector<int>> hashmap(26);

        for(int i=0;i<26;i++){
            hashmap[i].push_back(-1);
        }

        for(int i=0;i<s.size();i++){
            hashmap[s[i]-'A'].push_back(i);
        }

        for(int i=0;i<26;i++){
            hashmap[i].push_back(n);
        }
        long long count = 0;
        for(int i=0;i<26;i++){
            for(int j=1;j<hashmap[i].size()-1;j++){
                int left_cnt = hashmap[i][j] - hashmap[i][j-1];
                int right_cnt = hashmap[i][j+1]-hashmap[i][j];
                count += left_cnt*right_cnt;
            }
        }
        return count;
    }
};