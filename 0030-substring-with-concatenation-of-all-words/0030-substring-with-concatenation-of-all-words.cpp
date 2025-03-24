class Solution {
private:
    vector<int> solve(string s, vector<string>& words,int skip){
        int n = words.size();
        unordered_map<string, int> freq;
        unordered_map<string, int> cnt;
        for (int i = 0; i < n; i++) {
            cnt[words[i]]++;
            freq[words[i]]++;
        }
        int substr_cnt=0;
        int wordlen = words[0].length();
        vector<int> ans;
        int j =0;
        for(int i=0;i<(int)s.size();i+=wordlen){
            if(substr_cnt==0) j=i;
            string temp = s.substr(i,wordlen);
            if(cnt.find(temp)!=cnt.end()){
                freq[temp]--;
                substr_cnt++;
                while(j <= i && freq[temp]<0){
                    string temp2= s.substr(j,wordlen);
                    if(cnt.find(temp2)!=cnt.end()){
                        substr_cnt--;
                        freq[temp2]++;
                    }
                    j+=wordlen;
                }
            }else{
                while(j<=i){
                    string temp2= s.substr(j,wordlen);
                    if(cnt.find(temp2)!=cnt.end()){
                        substr_cnt--;
                        freq[temp2]++;
                    }
                    j+=wordlen;
                }
            }
            if(substr_cnt==n){
                ans.push_back(j+skip);
            } 
        }
        return ans;
    }

public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        int n = s.size();
        int wordlen = words[0].length();
        if(n < wordlen) return {};
        for(int i =0;i<wordlen;i++){
            vector<int> temp = solve(s.substr(i,n),words,i);
            for(auto x: temp) ans.push_back(x);
        }
        return ans;
    }
};