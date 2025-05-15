class Solution {
private:
    vector<string> ans;

    void solve(vector<string>& word, vector<int>& groups, int i, vector<string> curr, int prev){
        //base case
        if(i>=word.size()){
            if(ans.size()<curr.size()) {
                ans=curr;
            }
            return;
        }

        //rec case
        //case 1: can pick
        if(prev==-1 || prev != groups[i]){
            curr.push_back(word[i]);
            solve(word,groups,i+1,curr,groups[i]);
            curr.pop_back();
        }

        //case 2: do not pick and skip
        solve(word,groups,i+1,curr,prev);
        

    }
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string> curr;
        solve(words,groups,0,curr,-1);
        return ans;
    }
};