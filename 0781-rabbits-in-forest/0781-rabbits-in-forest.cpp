class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int> freq;
        int ans = 0;
        for(int i=0;i<answers.size();i++){
            freq[answers[i]]++;
        }
        for(auto it= freq.begin();it!=freq.end();it++){
            int val = it->second % (it->first+1) ; 
            if(val==0) ans += it->second;
            else{
                int num = it->second;
                int mul = it->first+1;
                int next_multiple = (num + mul -1) / mul;
                next_multiple *= mul;
                ans += next_multiple;
            } 
        }
        return ans;

    }
};