class Node{
    //private by default
    Node* links[2];
    bool containsKey(int bit){
        return (links[bit]!=NULL);
    }
    Node* get(int bit){
        return links[bit];
    }
    void put(int bit, Node* n){
        links[bit] = n;
    }
    friend class Trie;
};

class Trie{
    public:
        Node* root;
        Trie(){
            root = new Node();
        }

    public:
        void insert(int num){
            Node* node = root;
            for(int i=31;i>=0;i--){
                int bit = (num>>i) & 1 ;
                if(!node->containsKey(bit)){
                    node->put(bit,new Node());
                }
                node= node->get(bit);
            }
        }

        int getMax(int num){
            Node* node = root;
            int maxnum = 0;
            for(int i=31;i>=0;i--){
                int bit = (num>>i) & 1;
                if(node->containsKey(!bit)){
                    maxnum = maxnum | (1<<i);
                    node = node->get(!bit);
                }else{
                    node = node->get(bit);
                }
            }
            return maxnum;
        }

};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie trie;
        for(int i=0;i<nums.size();i++){
            trie.insert(nums[i]);
        }
        int maxXOR = 0;
        for(int i=0;i<nums.size();i++){
            maxXOR = max(maxXOR, trie.getMax(nums[i]));
        }
        return maxXOR;
    }
};