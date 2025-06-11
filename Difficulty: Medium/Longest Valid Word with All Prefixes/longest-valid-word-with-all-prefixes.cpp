

class TrieNode{
private:
    TrieNode* children[26];
    bool isEnd;

public:
    TrieNode(){
        isEnd = false;
        for(int i=0;i<26;i++){
            children[i] = nullptr;
        }
    }

    friend class Trie;
};

class Trie{
private:
    TrieNode* root;

public:
    Trie(){
        root = new TrieNode();
    }

    void insert(string word){
        TrieNode* temp = root;

        for(auto& ch: word){
            int idx = ch - 'a';
            if(!temp->children[idx]){
                temp->children[idx] = new TrieNode();
            }
            temp= temp->children[idx];
        }
        temp->isEnd = true;
    }

    bool check_prefix(string& word){
        TrieNode* temp = root;

        for(auto& ch: word){
            int idx = ch - 'a';
            if(!temp->children[idx]) return false;
            temp = temp->children[idx];
            if(temp->isEnd == false) return false;
        }
        return true;
    }
};


class Solution {
private:    
    static bool customCompare(const string &a, const string &b){
        if(a.length() != b.length()){
            return a.length() > b.length();
        }
        return a < b;
    }

public:
    string longestValidWord(vector<string>& nums) {
        //your code goes here
        Trie t;
        for(int i=0; i<nums.size();i++){
            t.insert(nums[i]);
        }

        sort(nums.begin(), nums.end(),customCompare);

        string ans="";
        bool isCheckTrue= false;
        for(int i =0; i< nums.size();i++){
            isCheckTrue = t.check_prefix(nums[i]);
            if(isCheckTrue){
                ans = nums[i];
                break;
            }
        }

        return ans;
    }
};
