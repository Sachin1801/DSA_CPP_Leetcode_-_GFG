class OrderedStream {
private:
    vector<string> v;
    int ptr;
    
public:
    OrderedStream(int n) {
        v.resize(n+1);
        ptr =1;
    }
    
    vector<string> insert(int idKey, string value) {
        vector<string> ans;
        v[idKey]=value;
        while(ptr< v.size() && !v[ptr].empty()){
            ans.push_back(v[ptr]);
            ptr++;
        }
        return ans;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */