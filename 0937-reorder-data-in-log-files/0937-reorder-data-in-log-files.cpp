class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {

        vector<vector<string>> dig;
        vector<vector<string>> alph;

        for (int i = 0; i < logs.size(); i++) {
            stringstream ss(logs[i]);
            string token;
            int cnt = 0;
            vector<string> temp;
            bool isdig = false;
            while (getline(ss, token, ' ')) {
                if (cnt == 0) {
                    temp.push_back(token);
                    cnt++;
                    continue;
                }

                // check if digit
                if (token[0] >= '0' && token[0] <= '9') {
                    isdig = true;
                }
                temp.push_back(token);
                cnt++;
            }
            if (isdig) {
                dig.push_back(temp);
            } else {
                alph.push_back(temp);
            }
        }

        auto compareWithKey = [](const vector<string>& a,
                                 const vector<string>& b) -> bool {
            if(lexicographical_compare(a.begin()+1, a.end(), b.begin()+1, b.end()) || lexicographical_compare(b.begin()+1,b.end(), a.begin()+1,a.end())){
                return lexicographical_compare(a.begin() + 1, a.end(),
                                               b.begin() + 1, b.end());
            }
            return a[0] < b[0];
        };

        sort(alph.begin(), alph.end(), compareWithKey);

        vector<string> ans;
        for(int i=0;i<alph.size();i++){
            string temp="";
            for(int j=0;j<alph[i].size();j++){
                if(j==alph[i].size()-1){
                    temp+= alph[i][j];
                    continue;
                }
                temp+= alph[i][j];
                temp+= ' ';
            }
            ans.push_back(temp);
        }

        for(int i=0;i<dig.size();i++){
            string temp="";
            for(int j=0;j<dig[i].size();j++){
                if(j==dig[i].size()-1){
                    temp+=dig[i][j];
                    continue;
                }
                temp+= dig[i][j];
                temp+= ' ';
            }
            ans.push_back(temp);
        }
        return ans;
    }
};