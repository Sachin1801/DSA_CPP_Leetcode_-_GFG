class Node{
    private:
        Node* links[2];

        bool containsKey(int num){
            return (links[num]!=NULL);
        }

        Node* get(int num){
            return links[num];
        }

        void put(int num, Node* n){
            links[num] = n;
        }
        friend class Trie;
};

class Trie{

public:
    Node* root;

    Trie(){
        root = new Node();
    }
    void insert(int num){
        Node* n = root;
        for(int i=31;i>=0;i--){
            int bit = (num>>i)&1;
            if(!n->containsKey(bit)){
                n->put(bit,new Node());
            }
            n = n->get(bit);
        }
    }

    int getMax(int num){
        int maxXOR = 0;
        Node* n = root;
        for(int i =31;i>=0;i--){
            int bit = (num>>i)&1;
            //if opposite bit exists
            if(n!=NULL && n->containsKey(!bit)){
                maxXOR = maxXOR | (1<<i);
                n = n->get(!bit);
            }else{
                if(n!=NULL && n->containsKey(bit))
                    n = n->get(bit);
            }
        }
        return (maxXOR==0) ? -1: maxXOR;
    }
};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        for(int i=0;i<queries.size();i++){
            queries[i].push_back(i);
        }
        auto cmp = [](vector<int> &A, vector<int> &B){
            return A[1]<B[1];
        };
        sort(nums.begin(),nums.end());
        sort(queries.begin(),queries.end(),cmp);
        int j =0;
        Trie trie;
        vector<int> ans(queries.size(),-1);
        for(int i =0;i<queries.size();i++){
            int end_val = queries[i][1];
            while(j < nums.size() && nums[j] <= end_val){
                trie.insert(nums[j]);
                j++;
            }
            int x = queries[i][0];
            int idx = queries[i][2];
            int maxXOR = trie.getMax(x);
            ans[idx]= maxXOR;
            
        }
        return ans;
    }
};