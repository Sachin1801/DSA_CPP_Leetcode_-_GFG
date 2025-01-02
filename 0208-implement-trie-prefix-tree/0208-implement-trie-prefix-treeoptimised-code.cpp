class TrieNode
{
    public:
    bool isWord;
    TrieNode *children[26];
    TrieNode()
    {
        isWord=false;
        for(int i=0;i<=25;i++)
        {
            children[i]=nullptr;
        }
    }
};
class Trie {
public:
    TrieNode *root=nullptr;
    Trie() {
        root=new TrieNode;
    }
    
    void insert(string word) {
        TrieNode *temp= root;
        for(auto w : word)
        {
            int ch=w-'a';
            if(temp->children[ch]==nullptr)
               temp->children[ch]=new TrieNode();
            temp=temp->children[ch];
        }
        temp->isWord=true;
    }
    
    bool search(string word) {
        TrieNode *temp= root;
        for(auto w : word)
        {
             int ch=w-'a';
            if(temp->children[ch]==nullptr)
              return false;
            temp=temp->children[ch];
        }
        return temp->isWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode *temp= root;
        for(auto w : prefix)
        {
             int ch=w-'a';
            if(temp->children[ch]==nullptr)
              return false;
            temp=temp->children[ch];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */