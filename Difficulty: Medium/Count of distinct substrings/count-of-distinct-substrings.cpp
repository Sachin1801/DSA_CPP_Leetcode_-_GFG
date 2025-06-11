class TrieNode{
public:
    unordered_map<char,TrieNode*> children;
    
    TrieNode(){}
};

class Trie{
    private:
        TrieNode* root;
        // int tot_size;
    public:
        Trie(){
            root = new TrieNode();
            // tot_size =0;
        }
        
        int insert(string st){
            TrieNode* node = root;
            int curr_size = 0;
            for(auto& ch:st ){
                if(node->children.find(ch) == node->children.end()){
                    node->children[ch] = new TrieNode();
                    curr_size++;
                }
                node = node->children[ch];
            }
            return curr_size;
        }
        
        // int get_size(){
        //     return tot_size;
        // }
};

/*You are required to complete this method */
int countDistinctSubstring(string s) {
    // Your code here
    int n = s.length();
    Trie t;
    int ans = 1;
    for(int i=0;i<n;i++){
        ans += t.insert(s.substr(i,n-i));
    }
    return ans;
    
}